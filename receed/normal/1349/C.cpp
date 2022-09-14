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

const int N = 1002, INF = 1e7;
int a[N][N], d[N][N], tr[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char s[N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m, t;
    cin >> n >> m >> t;
    rep(i, n) {
        cin >> s;
        rep(j, m)
            a[i][j] = s[j] - '0';
    }
    queue<pair<int, int>> q;
    rep(i, n)
        rep(j, m) {
            d[i][j] = INF;
            rep(k, 4) {
                int x = i + tr[k][0], y = j + tr[k][1];
                if (0 <= x && x < n && 0 <= y && y < m && a[x][y] == a[i][j]) {
                    d[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        rep(i, 4) {
            int cx = x + tr[i][0], cy = y + tr[i][1];
            if (0 <= cx && cx < n && 0 <= cy && cy < m && d[cx][cy] == INF) {
                d[cx][cy] = d[x][y] + 1;
                q.push({cx, cy});
            }
        }
    }
    rep(i, t) {
        ll x, y, p;
        cin >> x >> y >> p;
        x--; y--;
        if (d[x][y] == INF || p < d[x][y])
            cout << a[x][y] << '\n';
        else
            cout << (a[x][y] ^ ((p - d[x][y]) % 2)) << '\n';
    }
}