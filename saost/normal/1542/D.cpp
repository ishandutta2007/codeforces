#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=1; i<=r; ++i)
#define REP(i,l,r) for(int i=1; i<r; ++i)
using namespace std;
const long long N = 505, MOD = 998244353;
long long n, res, a[N], b[N], f[N][N];
bool ok[N];
char ch[505];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> ch[i];
        if (ch[i] == '+') cin >> a[i];
        else a[i] = -1;
    }
    for(int i=1; i<=n; ++i) b[i] = i;
    sort(b+1, b+n+1, [] (int A, int B) { return a[A] < a[B]; });
    for(int i=1; i<=n; ++i) if (a[b[i]] != -1) {
        f[0][0] = 1;
        ok[b[i]] = true;
        for(int j=1; j<=n; ++j) {
            if (j == b[i]) {
                for(int w=1; w<=n; ++w) f[j][w] = f[j-1][w-1];
            }
            else if (ok[j]) {
                f[j][0] = f[j-1][0];
                for(int w=1; w<=n; ++w) f[j][w] = (f[j-1][w] + f[j-1][w-1]) % MOD;
            }
            else if (a[j] != -1) {
                for(int w=0; w<=n; ++w) f[j][w] = (f[j-1][w] * 2) % MOD;
            }
            else {
                f[j][0] = (f[j-1][0] * 2 + f[j-1][1]) % MOD;
                for(int w=1; w<=n; ++w) f[j][w] = (f[j-1][w] + f[j-1][w+1]) % MOD;
            }
            if (b[i] <= j) f[j][0] = 0;
        }
        for(int j=1; j<=n; ++j)
            res = (res + a[b[i]] * f[n][j]) % MOD;
    }
    cout << res;
}