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
#define str string
using namespace std;
const int M = 1000000007;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n == m) {
            cout << n * (n + 1) / 2 << '\n';
        } else {
            int x = n - m;
            int ans = n * (n + 1) / 2;
            int k = m + 1;
            if (x >= k) {
                int q = x / k;
                int r = x % k;
                ans -= q * (q + 1) / 2 * (k - r);
                ans -= (q + 1) * (q + 2) / 2 * r;
                cout << ans << '\n';
            } else {
                cout << ans - x << '\n';
            }
        }
    }
}