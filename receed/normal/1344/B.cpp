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

const int N = 1001;
int a[N][N], f, c, n, m;
int used[N][N];
char s[N];
int tr[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void pt(int x) {
    if (x) {
        if (f < 2)
            f = 1;
        else {
            cout << -1;
            exit(0);
        }
    }
    else if (f == 1)
            f = 2;
}

void dfs(int x, int y) {
    used[x][y] = 1;
    rep(i, 4) {
        int cx = x + tr[i][0], cy = y + tr[i][1];
        if (0 <= cx && cx < n && 0 <= cy && cy < m && !used[cx][cy] && a[cx][cy])
            dfs(cx, cy);
    }
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int en = n, em = m;
    rep(i, n) {
        cin >> s;
        f = 0;
        rep(j, m) {
            a[i][j] = (s[j] == '#');
            pt(a[i][j]);
        }
        if (f)
            en--;
    }
    rep(i, m) {
        f = 0;
        rep(j, n)
            pt(a[j][i]);
        if (f)
            em--;
    }
    if ((en > 0) != (em > 0)) {
        cout << -1;
        return 0;
    }
    rep(i, n)
        rep(j, m)
            if (a[i][j] && !used[i][j]) {
                c++;
                dfs(i, j);
            }
    cout << c;
}