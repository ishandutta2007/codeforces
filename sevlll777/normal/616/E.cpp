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
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << 0;
        return 0;
    }
    if (n == 1) {
        cout << (m % M + M - 1) % M;
        return 0;
    }
    if (m <= 1e6) {
        int ans = 0;
        for (int p = 1; p <= m; p++) {
            ans += n % p;
            ans %= M;
        }
        cout << ans;
        return 0;
    }
    int ans = (n % M) * (m % M) % M;
    int s = floor(sqrt(n));
    int i = 1;
    while (n / i > s) {
        ans += M;
        ans -= (i * (n / i) % M);
        ans %= M;
        i++;
    }
    int left = 1;
    int right = s;
    for (int x = left; x <= right; x++) {
        int r = n / x, l = n / (x + 1) + 1;
        if (r > m) r = m;
        if (l < i) l = i;
        if (l <= r) {
            r %= M;
            l %= M;
            ans += M;
            int rs = r * ((M + r + 1) % M) % M * 500000004 % M;
            int ls = ((M + l - 1) % M) * l % M * 500000004 % M;
            int sm = (rs + M - ls) % M;
            ans -= (x * sm) % M;
            ans %= M;
        }
    }
    cout << ans;
}