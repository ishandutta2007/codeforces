#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;



#define MOD 1000000000

int n,m;
int a[200007];
long long f[150];

void input();
void solve();

int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=n;i++)
        {
        scanf("%d",&a[i]);
        }
    }


void solve()
    {
    int i,j;
    int t;
    int x,v;
    int l,r;
    long long ans=0;
    f[0]=1;
    f[1]=1;
    for(i=2;i<=100;i++)
        {
        f[i]=(f[i-2]%MOD+f[i-1]%MOD)%MOD;
        }
    ///cout<<f[100]<<"\n";
    for(i=0;i<m;i++)
        {
        scanf("%d",&t);
        if(t==1)
            {
            scanf("%d%d",&x,&v);
            a[x]=v;
            }
        else
            {
            scanf("%d%d",&l,&r);
            ans=0;
            for(j=0;j<=r-l;j++)
                {
                ans+=((f[j]%MOD)*(a[j+l]%MOD))%MOD;
                ans=ans%MOD;
                ///cout<<f[j]<< " " << a[j+l]<<"\n";
                ///cout<<ans<<"\n";
                }
            printf("%I64d\n",ans);
            }
        }
    }