#include<bits/stdc++.h>
#define MAXN 45
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int a[MAXN][MAXN];
bool f1[1<<20],f2[1<<20];
int con[1<<20];
int maxi[1<<20];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    int x=n/2,y=n-x;
    memset(f1,false,sizeof(f1));
    memset(f2,false,sizeof(f2));
    f1[0]=f2[0]=true;
    int ans=0;
    for(int mask=1;mask<(1<<x);mask++)
    {
        int lowbit=mask&-mask;
        int v=31-__builtin_clz(lowbit);
        bool f=true;
        for(int j=0;j<x;j++)
        {
            if(mask&(1<<j))
            {
                if(j!=v&&!a[j][v])
                {
                    f=false;
                    break;
                }
            }
        }
        if(!f) f1[mask]=false; else f1[mask]=f1[mask-lowbit];
        if(f1[mask]) ans=max(ans,__builtin_popcount(mask));
    }
    for(int mask=1;mask<(1<<y);mask++)
    {
        int lowbit=mask&-mask;
        int v=31-__builtin_clz(lowbit)+x;
        bool f=true;
        for(int j=0;j<y;j++)
        {
            if(mask&(1<<j))
            {
                if(j+x!=v&&!a[j+x][v])
                {
                    f=false;
                    break;
                }
            }
        }
        if(!f) f2[mask]=false; else f2[mask]=f2[mask-lowbit];
        if(f2[mask])
        {
            ans=max(ans,__builtin_popcount(mask));
            maxi[mask]=__builtin_popcount(mask);
        }
    }
    for(int i=0;i<y;i++)
        for(int j=0;j<(1<<y);j++)
            if(j&(1<<i)) maxi[j]=max(maxi[j],maxi[j^(1<<i)]);
    con[0]=(1<<y)-1;
    for(int i=1;i<(1<<x);i++)
    {
        int lowbit=i&-i;
        int v=31-__builtin_clz(lowbit);
        int mask=0;
        for(int j=0;j<y;j++) if(a[j+x][v]) mask|=(1<<j);
        con[i]=con[i-lowbit]&mask;
        if(f1[i]) ans=max(ans,__builtin_popcount(i)+maxi[con[i]]);
    }
    double res=k*k*(1.0/ans)*(ans-1)/2;
    printf("%.10f\n",res);
    return 0;
}