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
const int MAXN = 100500;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<bool> sieve(MAXN, true);
    sieve[1] = false;
    int n;
    cin >> n;
    vector<bool> used(MAXN, false);
    vector<int> trsh;
    vector<pair<int, int>> ans;
    vector<int> primes;
    for (int p = 2; p <= n / 2; p++) {
        if (sieve[p]) {
            for (int q = p + p; q <= n; q += p) sieve[q] = false;
            primes.pb(p);
        }
    }
    reverse(primes.begin(), primes.end());
    for (auto x : primes) {
        used[x] = true;
        vector<int> php;
        for (int q = x + x; q <= n; q += x) {
            if (!used[q]) {
                used[q] = true;
                php.pb(q);
            }
        }
        php.pb(x);
        if (php.size() % 2 == 0) {
            for (int i = 0; i < php.size(); i += 2) ans.pb({php[i], php[i + 1]});
        } else {
            trsh.pb(php.front());
            for (int i = 1; i < (int) php.size() - 1; i += 2) ans.pb({php[i], php[i + 1]});
        }
    }
    for (int i = 0; i < (int) trsh.size() - 1; i += 2) ans.pb({trsh[i], trsh[i + 1]});
    cout << ans.size() << '\n';
    for (auto p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }

}