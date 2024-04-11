#include<stdio.h>
using namespace std;
long have[5005]={0};
long tot=0;
long par[650000]={0};
long n;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%ld",&n);
    n*=2;
    for(long i=1;i<=n;i++)
    {
             long x;scanf("%ld",&x);
             if(have[x])
             {
                        par[have[x]]=i;
                        tot++;
                        have[x]=0;
                        }
             else have[x]=i;
             }
    if(tot!=n/2)
    {
                printf("-1\n");
                }
    else
    {
        for(long i=1;i<=n;i++)
        if(par[i])printf("%ld %ld\n",i,par[i]);
        }
    return 0;
}