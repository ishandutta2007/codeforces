#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define N 1010

int c[N][N], b[N];
char s[66][N];
long long a[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; i ++) c[0][i] = 0, c[i][0] = 1;
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) {
        c[i][j] = c[i-1][j] + c[i-1][j-1];
        if(c[i][j] >= mod) c[i][j] -= mod;
    }
    b[0] = 1;
    for(int i = 1; i <= n; i ++) for(int j = 0; j < i; j ++) b[i] = (b[i]+1ll*c[i-1][j]*b[j]) % mod;
    for(int i = 0; i < m; i ++) scanf("%s", s[i]+1);
    for(int i = 1; i <= n; i ++) for(int j = 0; j < m; j ++) if(s[j][i] == '1') a[i] ^= 1ll<<j;
    sort(a+1, a+n+1);
    int ans = 1;
    for(int i = 1, j = 1; i <= n; i = j) {
        while(j <= n && a[i] == a[j]) j ++;
        ans = 1ll * ans * b[j-i] % mod;
    }
    cout << ans << endl;
}