// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define int long long
const int N = 105, mod = (int) 1e9 + 7;
int a[N], adj[N][N], st[N][N], c[N][N], mat[70][N][N];

int mul(int a[N][N], int b[N][N]) {
    memset(c, 0, sizeof c);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                (c[i][j] += a[i][k] * b[k][j]) %= mod;
}




int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
//    sort(a, a + n);
//    n = unique(a, a + n) - a;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0)
                adj[i][j] = 1;
    for (int i = 0; i < n; ++i)
        st[i][i] = 1;
    --k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            mat[0][i][j] = adj[i][j];
    for (int i = 0; i < 62; ++i) {
        mul(mat[i], mat[i]);
        memcpy(mat[i + 1], c, sizeof mat[i + 1]);
    }
    for (int i = 0; i < 62; ++i) if (k >> i & 1) {
        mul(st, mat[i]);
        memcpy(st, c, sizeof st);
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            res += st[i][j], res %= mod;
    cout << res << '\n';


}