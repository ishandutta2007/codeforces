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
    string s;
    cin >> s;
    vector<int> pow10 = {1}, prefpow = {1}, prefprefpow = {1};
    for (int i = 1; i <= 2000000; i++) {
        pow10.pb((10 * pow10.back()) % M);
        prefpow.pb((prefpow[i - 1] + pow10[i]) % M);
        prefprefpow.pb((prefprefpow[i - 1] + prefpow[i]) % M);
    }
    int ans = 0;
    int n = (int) s.size();
    for (int i = 0; i < n; i++) {
        int sans = 0;
        int af = n - 1 - i;
        sans += (pow10[af] * ((i * (i + 1) / 2) % M)) % M;
        sans %= M;
        if (af) {
            sans += (af * prefpow[af - 1]) % M;
            sans %= M;
            if (af > 1) {
                sans += (M - prefprefpow[af - 2]) % M;
                sans %= M;
            }
        }
        sans *= (s[i] - '0');
        sans %= M;
        ans += sans;
        ans %= M;
    }
    cout << ans << '\n';

}