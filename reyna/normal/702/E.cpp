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
const int N = 1e5 + 5, L = 40, mod = 0;

int f[N][L], mn[N][L], sum[N][L];

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> f[i][0];
    for (int i = 0; i < n; ++i)
        cin >> sum[i][0], mn[i][0] = sum[i][0];
    for (int g = 1; g < L; ++g)
        for (int v = 0; v < n; ++ v)
            f[v][g] = f[f[v][g - 1]][g - 1], mn[v][g] = min(mn[v][g - 1], mn[f[v][g - 1]][g - 1]), sum[v][g] = sum[v][g - 1] + sum[f[v][g - 1]][g - 1];
    for (int v = 0; v < n; ++v) {
        int mres = 1e18, sres = 0, cur = v;
        for (int i = L - 1; i >= 0; --i)
            if (k >> i & 1) {
                mres = min(mres, mn[cur][i]);
                sres += sum[cur][i];
                cur = f[cur][i];
            }
        cout << sres << ' ' << mres << '\n';
    }




}