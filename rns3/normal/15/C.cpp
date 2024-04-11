#include<cstdio>
#define N 100010

long long x, y, ans;
int n;

long long bitx(long long a){
    if(a == 0 || a == 3) return 0;
    if(a == 1) return 1;
    if(a == 2) return 3;
    int k = 63 - __builtin_clzll(a);
    return bitx(a - (1ll << k)) + (1ll << k) * (1 - a % 2);
}

int main(){
    ans = 0;
    for(scanf("%d", &n); n --;){
        scanf("%I64d %I64d", &x, &y);
        ans ^= bitx(x - 1);
        ans ^= bitx(x + y - 1);
    }
    if( ans ) puts("tolik");
    else puts("bolik");
}