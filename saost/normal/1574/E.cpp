#include <bits/stdc++.h>
#include <queue>
using namespace std;
const long long N = 1e6 + 5, MOD = 998244353;
int m, n, k;
long long res;
int free_Row, free_Col, line_vert, line_hori;
int Num_Row[N], Num_Row2[N][2], Num_Col[N], Num_Col2[N][2];
int c[2][2];
map<pair<int,int>, int> M;

long long power(long long x, int k) {
    long long ans = 1;
    while (k) {
        if (k & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return ans;
}

void Calculate() {
    res = 0;
    if (line_vert && line_hori) return;
    if (!line_vert) (res += power(2, free_Row)) %= MOD;
    if (!line_hori) (res += power(2, free_Col)) %= MOD;
    if (!line_vert && !line_vert) {
        if (c[0][0] == 0 && c[1][1] == 0) (res += MOD - 1) %= MOD;
        if (c[0][1] == 0 && c[1][0] == 0) (res += MOD - 1) %= MOD;
    }
}

void Delete(int x, int y) {
    if (!M.count({x,y})) return;
    int z = M[{x,y}];
    M.erase({x,y});
    --c[z][(x+y) & 1];
    if (--Num_Row[x] == 0) ++free_Row;
    if (--Num_Row2[x][z ^ (y&1)] == 0 && Num_Row[x]) --line_vert;
    if (--Num_Col[y] == 0) ++free_Col;
    if (--Num_Col2[y][z ^ (x&1)] == 0 && Num_Col[y]) --line_hori;
}

void Add(int x, int y, int z) {
    M[{x,y}] = z;
    ++c[z][(x+y) & 1];
    if (Num_Row[x]++ == 0) --free_Row;
    if (Num_Row2[x][z ^ (y&1)]++ == 0 && Num_Row[x] > 1) ++line_vert;
    if (Num_Col[y]++ == 0) --free_Col;
    if (Num_Col2[y][z ^ (x&1)]++ == 0 && Num_Col[y] > 1) ++line_hori;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> m >> n >> k;
    free_Row = m;
    free_Col = n;
    line_hori = 0;
    line_vert = 0;

    int x, y, z;
    while (k--) {
        cin >> x >> y >> z;
        Delete(x, y);
        if (z >= 0) Add(x, y, z);
        Calculate();
        cout << res << '\n';
    }
}