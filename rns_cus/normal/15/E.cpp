#include<stdio.h>
#define M 1000000009ll
typedef __int64 ll;

int main(){
    int n;
    ll x, h, rlt;
    while(scanf("%d", &n) == 1){
        if(n == 2) {printf("%d\n", 10); continue;}
        if(n == 4) {printf("%d\n", 74); continue;}
        rlt = 5;
        x = 5, h = x;
        for(int i = 1; i < (n - 2)/ 2 - 1; i ++) {
            x = (2 * x + 3) % M;
            h  = h * x % M;
            rlt = (rlt + h) % M;
        }
        rlt = rlt * 4 % M;
        rlt = (rlt + 6) % M;
        rlt = (rlt * rlt * 2 + 2) % M;
        printf("%I64d\n", rlt);
    }
}