// #pragma GCC optimize("unroll-loops")

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
// #define int short
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmap unordered_map
#define unset unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 998244353;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q;
    while (q--) {
        int n, t, a, b; cin >> n >> t >> a >> b;
        vector<int> S(n);
        for (int i = 0; i < n; i++) cin >> S[i];
        vector<int> T(n);
        for (int i = 0; i < n; i++) cin >> T[i];
        vector<pii> tasks;
        for (int i = 0; i < n; i++) {tasks.pb({T[i], S[i]});}
        tasks.pb({0, -1});
        tasks.pb({t+1, -1});
        sort(tasks.begin(), tasks.end());
        vector<int> sufhard = {0};
        int cnt = 0;
        for (int i = n; i >= 0; i--) {
            cnt += tasks[i].second;
            sufhard.pb(cnt);
        }
        int x = 0;
        int y = 0;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            int ta = tasks[i].first, h = tasks[i].second;
            if (h == 1) {
                y++;
            } else if (h == 0) {
                x++;
            }
            int time = a * x + y * b;
            if (time < tasks[i + 1].first) {
                cnt = i;
                int hard = sufhard[n - i];
                int easy = (n - i) - sufhard[n - i];
                if (time + easy * a < tasks[i + 1].first) {
                    cnt += easy;
                    time += easy * a;
                    if (time + hard * b < tasks[i + 1].first) {
                        time += hard * b;
                        cnt += hard;
                    } else {
                        cnt += (tasks[i + 1].first - time - 1) / b;
                    }
                } else {
                    cnt += (tasks[i + 1].first - time - 1) / a;
                }
                ans = max(ans, cnt);
            }
        }
        cout << ans << '\n';
    }


}