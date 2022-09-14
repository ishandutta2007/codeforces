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

const int N = 2002, M = N * 8;
bitset<M> dp[N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
    cin >> n >> k;
    vector<string> ms = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    vector<int> m(10), a(n);
    rep(i, 10)
        rep(j, 7)
            if (ms[i][j] == '1')
                m[i] |= (1 << j);
    string s;
    rep(i, n) {
        cin >> s;
        rep(j, 7)
            if (s[j] == '1')
                a[i] |= (1 << j);
    }
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        rep(j, 10) {
            if ((a[i] & m[j]) != a[i])
                continue;
            int cc = __builtin_popcount(a[i] ^ m[j]);
            dp[i] |= (dp[i + 1] << cc);
        }
    }
    if (!dp[0][k]) {
        cout << -1;
        return 0;
    }
    rep(i, n) {
        for (int j = 9; j >= 0; j--) {
            if ((a[i] & m[j]) != a[i])
                continue;
            int cc = __builtin_popcount(a[i] ^ m[j]);
            if (cc <= k && dp[i + 1][k - cc]) {
                cout << j;
                k -= cc;
                break;
            }
        }
    }

}