#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll l,r,p,q,k;
int main()
{
    scanf("%I64d%I64d%I64d%I64d%I64d",&l,&r,&p,&q,&k);
    ll f=max(l,p),g=min(r,q);
    ll ans=g-f+1;
    if(k<=g&&k>=f) ans--;
    if(ans<0) ans=0;
    printf("%I64d\n",ans);
    return 0;
}