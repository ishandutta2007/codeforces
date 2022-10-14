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
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t0 = 1;
    while (t0--) {
        int n, k;
        cin >> n >> k;
        vector<int> c01, c10, c11;
        while (n--) {
            int a, b, t;
            cin >> t >> a >> b;
            if (a == 0 && b == 1) {
                c01.pb(t);
            } else if (a == 1 && b == 0) {
                c10.pb(t);
            } else if (a == 1 && b == 1) {
                c11.pb(t);
            }
        }
        sort(c01.rbegin(), c01.rend());
        sort(c10.rbegin(), c10.rend());
        sort(c11.rbegin(), c11.rend());
        if (((int) c11.size() + (int) min(c01.size(), c10.size())) < k) {
            cout << "-1\n";
        } else {
            int ans = 0;
            while (k--) {
                if (c11.empty()) {
                    int x = c10.back(), y = c01.back();
                    ans += x + y;
                    c10.pop_back();
                    c01.pop_back();
                } else if (c10.empty() || c01.empty()) {
                    int x = c11.back();
                    ans += x;
                    c11.pop_back();
                } else if (c10.back() + c01.back() < c11.back()) {
                    int x = c10.back(), y = c01.back();
                    ans += x + y;
                    c10.pop_back();
                    c01.pop_back();
                } else {
                    int x = c11.back();
                    ans += x;
                    c11.pop_back();
                }
            }
            cout << ans << '\n';
        }
    }

}