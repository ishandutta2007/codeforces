#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll a,b;
int main()
{
    scanf("%I64d %I64d",&a,&b);
    ll s=1;
    for(ll i=a+1;i<=b;i++)
    {
        s*=i%10;
        s=s%10;
        if(s==0) break;
    }
    printf("%I64d\n",s);
    return 0;
}