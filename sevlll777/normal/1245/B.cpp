// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #pragma GCC target ("unrool-loops")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmp unordered_map
#define unst unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int a, b, c, n;
        str st;
        cin >> n >> a >> b >> c >> st;
        vector<int> rs;
        vector<int> ps;
        vector<int> ss;
        for (int i = 0; i < n; i++) {
            if (st[i] == 'R') {
                rs.pb(i);
            } else if (st[i] == 'P') {
                ps.pb(i);
            } else {
                ss.pb(i);
            }
        }
        int r = rs.size(), p = ps.size(), s = ss.size();
        int cnt = min(a, s) + min(b, r) + min(c, p);
        if (cnt * 2 < n) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            str ans = "";
            for (int i = 0; i < n; i++) {
                ans.pb('4');
            }
            for (int i = 0; i < min(a, s); i++) {
                ans[ss[i]] = 'R';
            }
            for (int i = 0; i < min(b, r); i++) {
                ans[rs[i]] = 'P';
            }
            for (int i = 0; i < min(c, p); i++) {
                ans[ps[i]] = 'S';
            }
            a -= min(a, s);
            b -= min(b, r);
            c -= min(c, p);
            for (int i = 0; i < n; i++) {
                if (ans[i] == '4') {
                    if (a > 0) {
                        ans[i] = 'R';
                        a--;
                    } else if (b > 0) {
                        ans[i] = 'P';
                        b--;
                    } else {
                        ans[i] = 'S';
                        c--;
                    }
                }
            }
            cout << ans << '\n';
        }
    }

}