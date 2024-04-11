#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

vector<array<int, 3>> segs;

struct pt {
    ll x, y;
    pt(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
    bool operator< (const pt &o) const {
        if(y != o.y) return y < o.y;
        return x < o.x;
    }

    pt operator+(const pt& o) const { return pt(x + o.x, y + o.y); }
    pt operator-(const pt& o) const { return pt(x - o.x, y - o.y); }
};

ll cross(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}

bool left(pt a, pt b, pt c) {
    return cross(b - a, c - a) >= 0;
}

vector<pt> lhull(vector<pt> v) {
    sort(v.begin(), v.end());
    vector<pt> hull;
    int sz = 0;
    for(auto p : v) {
        while(sz >= 2 && left(hull[sz - 2], hull[sz - 1], p)) {
            hull.pop_back();
            sz--;
        }
        hull.push_back(p);
        sz++;
    }
    reverse(hull.begin(), hull.end());
    return hull;
}

vector<pt> rhull(vector<pt> v) {
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    vector<pt> hull;
    int sz = 0;
    for(auto p : v) {
        while(sz >= 2 && left(hull[sz - 2], hull[sz - 1], p)) {
            hull.pop_back();
            sz--;
        }
        hull.push_back(p);
        sz++;
    }
    reverse(hull.begin(), hull.end());
    return hull;
}

struct frac {
    ll a, b;
    frac(ll _a, ll _b) {
        ll d = __gcd(_a, _b);
        if(b == 0) {
            a = _a;
            b = _b;
            return;
        }
        a = _a / d;
        b = _b / d;
        if(b < 0) {
            a *= -1;
            b *= -1;
        }
    }

    bool operator< (const frac &o) const {
        if(b == 0 && o.b == 0)
            return a < o.a;
        return a * o.b < b * o.a;
    }

    bool operator== (const frac &o) const {
        return ((a == o.a) && (b == o.b));
    }
};

ostream& operator<< (ostream &out, frac &f) {
    out << f.a << "/" << f.b;
    return out;
}

ostream& operator<< (ostream &out, pt &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

vector<frac> slp, start, fin;
vector<pt> lefts, rights;

double f(pt p, frac slp) {
    double x = p.x, y = p.y;
    return x + (p.y * (double)slp.a)/(double)slp.b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    segs.resize(n);
    int xmx = INT_MIN, xmn = INT_MAX, ymn = INT_MAX, ymx = INT_MIN;
    for(int i = 0; i < n; i++) {
        int l, r, y;
        cin >> l >> r >> y;
        segs[i] = {y, l, r};
        lefts.push_back({l, y});
        rights.push_back({r, y});
        xmx = max(xmx, r);
        ymx = max(ymx, y);
        xmn = min(xmn, l);
        ymn = min(ymn, y);
    }
    if(ymn == ymx) {
        cout << xmx - xmn << '\n';
        return 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            auto up = segs[i], dn = segs[j];
            if(up[0] == dn[0])
                continue;
            if(up[0] < dn[0])
                swap(up, dn);
            frac f1 = frac(dn[1] - up[2], up[0] - dn[0]), f2 = frac(dn[2] - up[1], up[0] - dn[0]);
            start.push_back(f1);
            fin.push_back(f2);
            slp.push_back(f1);
            slp.push_back(f2);
            //slp.push_back(frac(dn[1] - up[1], up[0] - dn[0]));
            //slp.push_back(frac(dn[2] - up[2], up[0] - dn[0]));
        }
    }
    //slp.push_back(frac(1, 0));
    //slp.push_back(frac(-1, 0));
    sort(slp.begin(), slp.end());
    sort(start.begin(), start.end());
    sort(fin.begin(), fin.end());
    int pb = 0, pf = 0;
    slp.erase(unique(slp.begin(), slp.end()), slp.end());
    int cur = 0;
    vector<frac> chk;
    for(auto s : slp) {
        while(pf < fin.size() && fin[pf] == s) {
            pf++;
            cur--;
        }
        if(cur == 0)
            chk.push_back(s);
        while(pb < start.size() && start[pb] == s) {
            pb++;
            cur++;
        }
    }
    auto lch = lhull(lefts), rch = rhull(rights);
    /*for(auto p : lch)
        cout << p << " ";
    cout << '\n';
    for(auto p : rch)
        cout << p << " ";
    cout << '\n';*/
    int pl = 0, pr = 0;
    double ans = 1e18;
    for(auto s : chk) {
        while(pl + 1 < lch.size() && f(lch[pl + 1], s) < f(lch[pl], s))
            pl++;
        while(pr + 1 < rch.size() && f(rch[pr + 1], s) > f(rch[pr], s))
            pr++;
        //cout << s << " " << rch[pr] << " " << lch[pl] << " " << f(rch[pr], s) - f(lch[pl], s) << '\n';
        ans = min(ans, f(rch[pr], s) - f(lch[pl], s));
    }
    cout << fixed << setprecision(9) << ans << '\n';
}