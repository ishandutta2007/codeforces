#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n;
    cin >> t;
    rep(z, t) {
        string s;
        cin >> s;
        n = s.size();
        vector<int> mp(2 * n - 1);
        int l = 0, r = 0;
        rep(i, 2 * n - 1) {
            if ((l + r) * 2 - i >= 0)
                mp[i] = max(0, min(mp[(l + r) * 2 - i], r * 2 + 1 - i));
            mp[i] = max(mp[i], 1 - i % 2);
            while ((i - mp[i]) >= 0 && (i + mp[i]) / 2 + 1 < n && s[(i - mp[i]) / 2] == s[(i + mp[i]) / 2 + 1])
                mp[i] += 2;
            if ((i + mp[i]) / 2 > r) {
                l = (i - mp[i] + 2) / 2;
                r = (i + mp[i]) / 2;
            }
        }
       // rep(i, 2 * n + 1)
        //     cout << mp[i] << '\n';
        int mx = 0, pr = 0, pos = 0;
        while ((mx + 1) * 2 <= n && s[mx] == s[n - 1 - mx])
            mx++;
        int al = mx, ar = mx;
        rep(i, 2 * n - 1)
            if (mx * 2 + mp[i] >= min(i, n * 2 - 2 - i) + 1 && min(i, 2 * n - 2 - i) + 1 > al + ar) {
                if (i < 2 * n - i) {
                    al = i + 1 - mx;
                    ar = mx;
                }
                else {
                    al = mx;
                    ar = 2 * n - i - 1 - mx;
                }
            }
        cout << s.substr(0, al) + s.substr(n - ar) << '\n';
    }
}