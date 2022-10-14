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

int binpow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x & 1) {
            ans *= a; ans %= M; x--;
        } else {
            a *= a; a %= M;
            x >>= 1;
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> presents(1e6 + 100);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x; presents[x].pb(k);
        }
    }
    int ans = 0;
    int p = binpow(n * n % M, M - 2);
    for (int i = 0; i < 1e6 + 100; i++) {
        int sj = 0;
        for (auto x : presents[i]) {
            sj += binpow(x, M - 2);
            sj %= M;
        }
        ans += presents[i].size() * p % M * sj % M;
        ans %= M;
    }
    cout << ans << '\n';

}