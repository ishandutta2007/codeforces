// C .
#include<stdio.h>
#define mod 9

int a[15], n, r;
long long ans;

int main(){
    scanf("%d", &n);
    r = n % mod;
    for(int i = 0; i < mod; i ++){
        a[i] = n / mod;
    }
    for(int i = 1; i <= r; i ++) a[i] ++;
    for(int i = 0; i < mod; i ++){
        for(int j = 0; j < mod; j ++){
            ans += 1ll * a[i] * a[j] * a[(i * j) % mod];
        }
    }
    for(int i = 1; i <= n; i ++) ans -= n / i;
    printf("%I64d\n", ans);
}