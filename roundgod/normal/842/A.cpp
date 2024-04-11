#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
int main()
{
    ll l,r,x,y,k;
    scanf("%I64d %I64d %I64d %I64d %I64d",&l,&r,&x,&y,&k);
    int f=0;
    for(int i=x;i<=y;i++)
        if(k*i>=l&&k*i<=r) {f=1; break;}
    if(f) printf("YES\n"); else printf("NO\n");
    return 0;
}