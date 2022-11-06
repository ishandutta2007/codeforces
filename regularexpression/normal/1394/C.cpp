#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

#define all(a) (a).begin(), (a).end()

template<class T1, class T2> inline bool ckmin(T1& x, T2 y) {if (y < x) {x = y; return 1;} return 0;}
template<class T1, class T2> inline bool ckmax(T1& x, T2 y) {if (y > x) {x = y; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        p[i] = {count(all(s), 'B'), count(all(s), 'N')};
    }
    const int N = 1e7;
    pair<int, int> ans;
    auto ok = [&](int m) {
        int lx = -N, rx = N, ly = -N, ry = N, l_diag = -N, r_diag = N;
        for (int i = 0; i < n; ++i) {
            ckmax(lx, p[i].F);
            ckmin(rx, p[i].F+2*m);
            ckmax(ly, p[i].S);
            ckmin(ry, p[i].S+2*m);
            ckmax(l_diag, p[i].F-p[i].S-m);
            ckmin(r_diag, p[i].F+m-p[i].S);
        }
        ckmax(l_diag, lx-ry);
        ckmin(r_diag, rx-ly);
        if (lx <= rx && ly <= ry && l_diag <= r_diag && (rx || ry)) {
            for (int x = lx; x <= rx; ++x) {
                int cly = max(ly, x-r_diag), cry = min(ry, x-l_diag);
                if (cly <= cry) ans = {x-m, cry-m};
            }
            return 1;
        }
        return 0;
    };
    int l = -1, r = N;
    while (r - l > 1) {
        int m = (l+r)/2;
        (ok(m) ? r : l) = m;
    }
    ok(r);
    cout << r << '\n' << string(ans.F, 'B') << string(ans.S, 'N');
    return 0;
}