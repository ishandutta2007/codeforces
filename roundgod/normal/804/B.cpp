#include<bits/stdc++.h>
#define MAXN 1000005
#define MOD 1000000007
using namespace std;
typedef long long ll;
char a[MAXN];
ll pow_mod(ll a,ll i)
{
    if(i==0) return 1;
     ll s=1;
    while(i>0)
     {
         if(i&1) s=(s*a)%MOD;
         a=(a*a)%MOD;
         i>>=1;
     }
     return s;
}
int main()
{
    scanf("%s",a);
    int k=0,cnt=0,n=strlen(a);
    ll ans=0;
    while(k<n&a[k]=='b')
        k++;
    if(k>=n)
    {
        printf("0\n");
        return 0;
    }
    while(k<n)
    {
        while(a[k]=='a'&&k<n)
        {
            cnt++;
            k++;
        }
        if(k>=n)
        {
            printf("%I64d\n",ans);
            return 0;
        }
        int x=0;
        while(a[k]=='b'&&k<n)
        {
            x++;
            k++;
        }
        ans=(ans+(pow_mod(2,cnt)-1)*x)%MOD;
    }
    printf("%I64d\n",ans);
    return 0;
}