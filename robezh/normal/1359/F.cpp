#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int N = 25005;
typedef long double ld;

const ld EPS = 1E-12;

struct pt {
    ld x, y;
};

struct seg {
    pt p, q;
    int id;
    seg(pt _p, pt _q, int _id) {
        if(_p.x > _q.x) swap(_p, _q);
        p = _p, q = _q;
        id = _id;
    }

    ld get_y(ld x) const {
        if (abs(p.x - q.x) < EPS)
            return p.y;
        return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
    }


};

bool intersect1d(ld l1, ld r1, ld l2, ld r2) {
    if (l1 > r1)
        swap(l1, r1);
    if (l2 > r2)
        swap(l2, r2);
    return max(l1, l2) <= min(r1, r2) + EPS;
}

int vec(const pt& a, const pt& b, const pt& c) {
    ld s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return abs(s) < EPS ? 0 : s > 0 ? +1 : -1;
}

bool intersect(const seg& a, const seg& b)
{
    return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
           intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
           vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0 &&
           vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
}

bool operator<(const seg& a, const seg& b)
{
    ld x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
    if(abs(a.get_y(x) - b.get_y(x)) < EPS)
        return a.id < b.id;
    return a.get_y(x) < b.get_y(x);
}

struct event {
    ld x;
    int tp, id;

    event() {}
    event(ld x, int tp, int id) : x(x), tp(tp), id(id) {}

    bool operator<(const event& e) const {
        if (abs(x - e.x) > EPS)
            return x < e.x;
        return tp > e.tp;
    }
};

set<seg> s;
vector<set<seg>::iterator> where;

set<seg>::iterator prev(set<seg>::iterator it) {
    return it == s.begin() ? s.end() : --it;
}

set<seg>::iterator next(set<seg>::iterator it) {
    return ++it;
}

pair<int, int> solve(const vector<seg>& a) {
    int n = (int)a.size();
    vector<event> e;
    for (int i = 0; i < n; ++i) {
        e.push_back(event(min(a[i].p.x, a[i].q.x), +1, i));
        e.push_back(event(max(a[i].p.x, a[i].q.x), -1, i));
    }
    sort(e.begin(), e.end());

    s.clear();
    where.resize(a.size());
    for (size_t i = 0; i < e.size(); ++i) {
        int id = e[i].id;
        if (e[i].tp == +1) {
//            cout << "in " << id << endl;
            set<seg>::iterator nxt = s.lower_bound(a[id]), prv = prev(nxt);
            if (nxt != s.end() && intersect(*nxt, a[id]))
                return make_pair(nxt->id, id);
            if (prv != s.end() && intersect(*prv, a[id]))
                return make_pair(prv->id, id);
            where[id] = s.insert(nxt, a[id]);
        } else {
//            cout << "out " << id << endl;
            set<seg>::iterator nxt = next(where[id]), prv = prev(where[id]);
            if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
                return make_pair(prv->id, nxt->id);
            s.erase(where[id]);
        }
    }

    return make_pair(-1, -1);
}

int n;

struct car {
    ld x, y, dx, dy, s;
    void read() {
        cin >> x >> y >> dx >> dy >> s;
        ld len = hypot(dx, dy);
        dx /= len, dy /= len;
    }
} c[N];

bool check(ld t) {
    vector<seg> segs;
    for(int i = 0; i < n; i++) {
        segs.push_back(seg({c[i].x, c[i].y}, {c[i].x + c[i].dx * c[i].s * t, c[i].y + c[i].dy * c[i].s * t}, i));
    }
    return solve(segs).first != -1;
}


int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);


    cin >> n;
    for(int i = 0; i < n; i++) c[i].read();

    // need to set r;
    ld l = 0, r = 1e13, mid;
    for(int i = 0; i < 100; i++) {
        mid = (l + r) / 2;
//        cout << mid << endl;
        if(check(mid)) r = mid;
        else l = mid;
    }
    if(!check(r)) cout << "No show :(" << '\n';
    else cout << fixed << setprecision(10) << r << '\n';
}