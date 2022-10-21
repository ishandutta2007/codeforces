#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + (int)1e5, mod = (int)1e9 + 7;

int n,a;
int cnt[N], f[22][N];
int pw2[N];

int count_1(int x){
    int res = 0;
    while(x > 0){res += x % 2; x /= 2;}
    return res;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        cnt[a] ++;
    }

    pw2[0] = 1;
    for(int i = 1; i <= (1 << 20); i++) pw2[i] = (pw2[i-1] * 2) % mod;
    for(int j = 0; j < (1 << 20); j++) f[20][j] = cnt[j];
    for(int i = 19; i >= 0; i--){
        for(int j = 0; j < (1 << 20); j++){
            if(j & (1 << i)) f[i][j] = f[i+1][j];
            else f[i][j] = (f[i+1][j] + f[i+1][j+(1<<i)]) % mod;
        }
    }

    int ans = 0;
    for(int i = 0; i < (1 << 20); i++){
        int cur = (count_1(i) % 2 ? -pw2[f[0][i]] : pw2[f[0][i]]);
        ans = (ans + cur) % mod;
    }
    printf("%d", (ans + mod) % mod);
}