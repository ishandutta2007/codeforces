#include<bits/stdc++.h>
using namespace std;
main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int mn = min(a,c);
    mn = min(mn,d);
    long long ans = 1ll *256*mn + 32 * min(a - mn,b);
    printf("%I64d",ans);
}