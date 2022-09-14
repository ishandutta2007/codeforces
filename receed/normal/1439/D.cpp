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

const int N = 503;
ll dc[N], ds[N], c2[N][N], s2[N][N], p, c[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m, p;
    cin >> n >> m >> p;
    dc[0] = 1;
    rep(i, n + 1) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
    }
    for (int i = 1; i <= n; i++) {
        rep(j, i) {
            dc[i] = (dc[i] + dc[j] * dc[i - 1 - j] % p * c[i - 1][j]) % p;
            ds[i] = (ds[i] + (dc[j] * ds[i - 1 - j] % p * (i + 1) % p + ds[j] * dc[i - 1 - j] % p * (i + 1) % p + (j * (j + 1) / 2 + (i - 1 - j) * (i - j) / 2) % p * dc[j] % p * dc[i - 1 - j] % p) % p * c[i - 1][j]) % p;
        }
        dc[i] = dc[i] * (i + 1) % p;
    }
    c2[0][0] = 1;
    rep(i, n + 1)
        for (int j = 0; j <= m; j++)
            for (int k = 0; i + k <= n && j + k <= m; k++) {
                c2[i + k + 1][j + k] = (c2[i + k + 1][j + k] + c2[i][j] * dc[k] % p * c[j + k][k]) % p;
                s2[i + k + 1][j + k] = (s2[i + k + 1][j + k] + (c2[i][j] * ds[k] % p + s2[i][j] * dc[k] % p) % p * c[j + k][k] % p) % p;
            }
    cout << s2[n + 1][m];
}