#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef map<int,int>::iterator mit;

int q;

bool bad(pii p0, pii p1, pii p2) {
    //(y1 - y0) / (x1 - x0) < (y2 - y1) / (x2 - x1);
    return 1LL * (p1.second - p0.second) * (p2.first - p1.first)
            <= 1LL * (p2.second - p1.second) * (p1.first - p0.first);
}

struct UpperHull {
    map<int, int> H;

    void insert(int x, int y) {
        if(check(x, y)) return ;
        H[x] = y;
        
        mit i = H.lower_bound(x);
        if(i != H.begin()) {
            for (auto j = --i; j != H.begin(); ) {
                i = j--;
                if (bad(*j, *i, pii{x, y})) H.erase(i);
                else break;
            }
        }

        i = H.upper_bound(x);
        if(i != H.end()) {
            for (auto j = i++; i != H.end(); j = i++) {
                if (bad(pii{x, y}, *j, *i)) H.erase(j);
                else break;
            }
        }
    }

    bool check(int x, int y) {
        auto it = H.find(x);
        if(it != H.end()) return it->second >= y;
        auto r = H.lower_bound(x);
        if(r == H.end() || r == H.begin()) return false;
        auto l = r; l--;
        return bad(*l, pii{x, y}, *r);
    }
} U, D;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> q;
    while(q--) {
        int t, x, y; cin >> t >> x >> y;
        if(t == 1) {
            U.insert(x, y);
            D.insert(x, -y);
        } else {
            cout << (U.check(x, y) && D.check(x, -y) ? "YES" : "NO") << '\n';
        }
    }
}