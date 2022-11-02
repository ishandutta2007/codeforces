#include<bits/stdc++.h>
using namespace std;
struct day{
    int s,c;
}a [100010];
int cmp(day a,day b){
    return min(2*a.s,a.c) - min(a.s,a.c) > min(2* b.s,b.c) - min(b.s,b.c);
}
main(){
    long long ans = 0;
    int n,f,i;
    scanf("%d%d",&n,&f);
    for(i = 0 ; i < n ; i++)
        scanf("%d%d",&a[i].s,&a[i].c);
    sort(a, a +n,cmp);
    for(i = 0 ; i < f; i++)
        a[i].s *= 2;
    for(i = 0 ; i < n ; i++)
        ans += min(a[i].s,a[i].c);
    printf("%I64d\n",ans);
}