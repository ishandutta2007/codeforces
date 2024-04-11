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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 1 << 20, MOD = 1e9 + 7;

void add(ll &x, ll y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    ll n = s.size(), z = 0, fz = 0;
    vector<pair<ll, ll>> li;
    ll ans = 0;
    rep(i, n) {
        z++;
        if (s[i] == '1') {
            if (fz == 0) {
                fz = z;
                z = 0;
                continue;
            }
            ll ca = (ans + 1) % MOD, cz = z;
            ans = (ans + ca * z) % MOD;
            while (!li.empty() && z > 0) {
                if (li.back().first <= z) {
                    ans = (ans + MOD - li.back().second * li.back().first % MOD) % MOD;
                    z -= li.back().first;
                    li.pop_back();
                }
                else {
                    ans = (ans + MOD - li.back().second * z % MOD) % MOD;
                    li.back().first -= z;
                    z = 0;
                }
            }
            li.push_back({cz, ca});
            z = 0;
        }
    }
    ans = (ans + 1) * fz % MOD * (z + 1) % MOD;
    if (!fz)
        ans = n;
    cout << ans;
}