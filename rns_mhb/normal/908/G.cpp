#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define N 707

char s[N];
int n, pw[11][N], c[N][N];

void init() {
    for(int i = 0; i < 11; i ++) {
        pw[i][0] = 1;
        for(int j = 1; j < N; j ++) pw[i][j] = 1ll * i * pw[i][j-1] % mod;
    }
    for(int i = 0; i < N; i ++) c[0][i] = 0, c[i][0] = 1;
    for(int i = 1; i < N; i ++) for(int j = 0; j < N; j ++) {
        c[i][j] = c[i-1][j] + c[i-1][j-1];
        if(c[i][j] >= mod) c[i][j] -= mod;
    }
}

int ans, cnt[10], pre[N], suf[N];

void solve(int k) {
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i <= k; i ++) cnt[s[i]-'0'] ++;
    for(int d = 1; d < 10; d ++) {
        int a = 0, b = 0;
        for(int i = 0; i < d; i ++) a += cnt[i];
        for(int i = 9; i > d; i --) b += cnt[i];
        for(int i = 0; i < a; i ++) pre[i] = 0, suf[i] = 0;
        for(int i = n-b; i < n; i ++) pre[i] = 0, suf[i] = 0;
        for(int i = a; i < n-b; i ++) {
            if(cnt[d] == 0) {
                int x = i-a, y = n-b-i;
                pre[i] = 1ll * c[x+y][x] * pw[d][x] % mod * (pw[10-d][y]-pw[9-d][y]+mod) % mod;
                x = n-b-i-1, y = i-a+1;
                suf[i] = 1ll * c[x+y][x] * pw[9-d][x] % mod * (pw[d+1][y]-pw[d][y]+mod) % mod;
            }
            else {
                int x = i-a, y = n-b-i-cnt[d];
                pre[i] = 1ll * c[x+y][x] * pw[d][x] % mod * pw[10-d][y] % mod;
                x = n-b-i-1, y = i-a+1-cnt[d];
                suf[i] = 1ll * c[x+y][x] * pw[9-d][x] % mod * pw[d+1][y] % mod;
            }
        }
        int g = 0;
        for(int i = 0; i < n; i ++) {
            g += pre[i];
            if(g >= mod) g -= mod;
            if(i) {
                g -= suf[i-1];
                if(g < 0) g += mod;
            }
            ans = (ans + 1ll * g * pw[10][n-i-1] % mod * d) % mod;
        }
    }
}

int main() {
    init();
    scanf("%s", s);
    n = strlen(s);
    ans = 0;
    for(int i = 0; i < n; i ++) {
        char up = s[i];
        for(s[i] = '0'; s[i] < up; s[i] ++) solve(i);
    }
    solve(n-1);
    cout << ans << endl;
}