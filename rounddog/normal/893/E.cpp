#include<bits/stdc++.h>
#define maxn 1000005
#define mod 1000000007

using namespace std;
typedef long long ll;

pow_(ll x,ll y)
{
    if (y==0) return 1;
    ll tmp=pow_(x,y/2);tmp=tmp*tmp%mod;
    if (y&1) tmp=tmp*x%mod; return tmp;
}

ll p[100],r,d[10],n,m,k,f[maxn];
ll ans;

int main()
{
    int query;
    scanf("%d",&query);
    p[0]=1;p[1]=1;
    for (int i=2;i<=20;i++) p[i]=p[i-1]*pow_(i,mod-2)%mod;
    f[0]=1;
    for (int i=1;i<maxn;i++) f[i]=f[i-1]*2%mod;
    while (query--)
    {
        scanf("%d%d",&n,&m);
        for (int i=0;i<10;i++) d[i]=0;
        k=0;r=2;
        while (r*r<=n)
        {
            if (n%r==0){
                while (n%r==0){
                    d[k]++;n/=r;
                }
                k++;
            }
            r++;
        }
        if (n!=1) d[k++]=1;
        ans=1;
        for (int i=0;i<k;i++)
        {
            for (int j=0;j<d[i];j++) ans=ans*(m+j)%mod;
            ans=ans*p[d[i]]%mod;
        }
        ans=ans*f[m-1]%mod;
        printf("%d\n",ans);
    }
    return 0;
}