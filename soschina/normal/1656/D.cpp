#include <cstdio>
#include <iostream>
using namespace std;

int t;
long long n, m;

int main(){
    scanf("%d", &t);
    while(t--){
        m = 1;
        scanf("%lld", &n);
        if(n & 1) puts("2");
        else{
            n *= 2;
            while(n % 2 == 0) n /= 2, m *= 2;
            long long ans = min(n, m);
            if(ans == 1) puts("-1");
            else printf("%lld\n", ans);
        }
    }
    return 0;
}