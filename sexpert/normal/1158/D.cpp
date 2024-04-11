#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T>
struct pt {
    T x, y;
    int idx;
    pt(T x = 0, T y = 0, int idx = 0) : x(x), y(y), idx(idx) {}
    bool operator< (pt o) const {return (x < o.x || (x == o.x && y < o.y)); }
    bool operator== (pt o) const {return (x == o.x && y == o.y);}
    pt operator+ (pt o) const {return pt(x + o.x, y + o.y);}
    pt operator- (pt o) const {return pt(x - o.x, y - o.y);}
    pt operator * (T l) const {return pt(l*x, l*y);}
    pt operator/ (T l) const {return pt(x/l, y/l);}
    T dot(pt o) { return x*o.x + y*o.y; }
    T cross(pt o) { return x*o.y - y*o.x; }
    T cross(pt a, pt b) { return (a - * this).cross(b - * this); }
    T normsq(pt o) { return x*x +y*y; }
    double norm(pt o) { return hypot(x, y); }
};

typedef pt<ll> po;
vector<po> res;
bool taken[2005];

vector<pt<ll>> convex_hull(vector<pt<ll>> P) {
    int n = P.size();
    if(n <= 2) return P;
    vector<pt<ll>> L, U;
    sort(P.begin(), P.end());
    for(int i = 0; i < n; i++) {
        while(U.size() >= 2 && U[U.size() - 2].cross(U[U.size() - 1], P[i]) >= 0)
        U.pop_back();
        while(L.size() >= 2 && L[L.size() - 2].cross(L[L.size() - 1], P[n-i-1]) >= 0)
        L.pop_back();
        U.push_back(P[i]), L.push_back(P[n - i - 1]);
    }
    U.insert(U.end(), L.begin() + 1, L.end() - 1);
    return U;
}

int main() {
    int n;
    cin >> n;
    vector<po> poly;
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        poly.push_back({x, y, i + 1});
    }
    auto ch = convex_hull(poly);
    string s;
    cin >> s;
    if(s[0] == 'R') {
        res.push_back(ch[0]);
        res.push_back(ch[1]);
    }
    else {
        res.push_back(ch[1]);
        res.push_back(ch[0]);
    }
    taken[ch[0].idx] = taken[ch[1].idx] = true;
    for(int i = 1; i <= n - 2; i++) {
        po cur;
        int st = 0;
        bool lf = (i < n - 2) ? (s[i] == 'L') : true;
        for(int j = 0; j < n; j++) {
            if(!taken[poly[j].idx]) {
                cur = poly[j];
                break;
                st = j + 1;
            }
        }
        for(int j = st + 1; j < n; j++) {
            if(taken[poly[j].idx]) continue;
            bool b = (res[i].cross(cur, poly[j]) <= 0);
            if(lf && b)
                cur = poly[j];
            if(!lf && !b)
                cur = poly[j];
        }
        res.push_back(cur);
        taken[cur.idx] = true;
    }
    for(int i = 0; i < n; i++)
        cout << res[i].idx << " ";
    cout << endl;
}