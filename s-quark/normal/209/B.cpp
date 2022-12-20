#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

long long a[3];

int main(){
#ifdef __FIO
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%I64d%I64d%I64d", &a[0], &a[1], &a[2]);
    long long ans = a[0]+a[1]+a[2];
    int i;
    for(i = 0; i < 3; i++){
        if((a[i]+a[(i+1)%3])%2 == 0)
            ans = min(ans, max(a[i], a[(i+1)%3]));
    }
    printf("%I64d\n", ans);
    return 0;
}