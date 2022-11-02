#include<bits/stdc++.h>
using namespace std;

#define N 2005

typedef unsigned long long ull;

const ull B = 503;
const int mod = 1e9 + 7;

ull h[3][N][N], p[N];
int L[2][N][N], R[2][N][N];
char s[3][N];

int main() {
    p[0] = 1;
    for(int i = 1; i < N; i ++) p[i] = p[i-1] * B;
    for(int i = 0; i < 3; i ++) scanf("%s", s[i] + 1);
    int n = strlen(s[0] + 1), k = strlen(s[2] + 1);
    for(int i = 0; i < 3; i ++) {
        int nn = (i == 2 ? k : n);
        for(int x = 1; x <= nn; x ++) {
            h[i][x][x] = s[i][x];
            for(int y = x + 1; y <= nn; y ++) h[i][x][y] = h[i][x][y-1] * B + s[i][y];
            for(int y = x - 1; y; y --) h[i][x][y] = h[i][x][y+1] * B + s[i][y];
        }
    }
    for(int i = 1; i <= n; i ++) for(int j = k; j; j --) for(int x = 0; x < 2; x ++) {
        if(s[x][i] != s[2][j]) continue;
        if(j == k) {
            L[x][i][j] = 1;
            continue;
        }
        L[x][i][j] = L[x][i-1][j+1];
        if(k - j & 1) {
            int len = k - j + 1 >> 1;
            if(len <= i && h[x][i][i-len+1] * p[len] + h[x^1][i-len+1][i] == h[2][j][k]) L[x][i][j] ++;
        }
        if(s[x][i] == s[2][j] && s[x^1][i] == s[2][j+1]) L[x][i][j] += L[x^1][i-1][j+2];
        L[x][i][j] %= mod;
    }
    for(int i = n; i; i --) for(int j = k; j; j --) for(int x = 0; x < 2; x ++) {
        if(s[x][i] != s[2][j]) continue;
        if(j == k) {
            R[x][i][j] = 1;
            continue;
        }
        R[x][i][j] = R[x][i+1][j+1];
        if(k - j & 1) {
            int len = k - j + 1 >> 1;
            if(len <= n-i+1 && h[x][i][i+len-1] * p[len] + h[x^1][i+len-1][i] == h[2][j][k]) R[x][i][j] ++;
        }
        if(s[x][i] == s[2][j] && s[x^1][i] == s[2][j+1]) R[x][i][j] += R[x^1][i+1][j+2];
        R[x][i][j] %= mod;
    }
    long long ans = 0;
    for(int x = 0; x < 2; x ++) for(int i = 1; i <= n; i ++) {
        if(s[x][i] != s[2][1]) continue;
        if(k == 1) {
            ans ++;
            continue;
        }
        for(int j = i + 1; j <= n; j ++) {
            int len = j - i + 1;
            if(s[x][j] != s[2][len]) break;
            if(k == len) ans ++;
            else {
                if(s[x^1][j] == s[2][len+1]) ans += R[x^1][j+1][len+2];
                if(k <= 2 * len && (h[x][i][j]*p[k-len]+h[x^1][j][j-k+len+1] == h[2][1][k])) ans ++;
                if(k > 2 * len && (h[x][i][j]*p[len]+h[x^1][j][i] == h[2][1][2*len])) ans += L[x^1][i-1][2*len+1];
            }
        }
        if(s[x^1][i] == s[2][2]) {
            if(k == 2) ans ++;
            else ans += L[x^1][i-1][3] + R[x^1][i+1][3];
        }
        for(int j = i - 1; j; j --) {
            int len = i-j+1;
            if(s[x][j] != s[2][len]) break;
            if(k == len) ans ++;
            else {
                if(s[x^1][j] == s[2][len+1]) ans += L[x^1][j-1][len+2];
                if(k <= 2 * len && (h[x][i][j]*p[k-len]+h[x^1][j][j+k-len-1] == h[2][1][k])) ans ++;
                if(k > 2 * len && (h[x][i][j]*p[len]+h[x^1][j][i] == h[2][1][2*len])) ans += R[x^1][i+1][2*len+1];
            }
        }
    }
    ans %= mod;
    printf("%I64d\n", ans);
}