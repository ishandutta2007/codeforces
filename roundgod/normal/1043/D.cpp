/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-28 23:51:45
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define BASE1 19260817
#define BASE2 19991020
#define MOD1 998244353
#define MOD2 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[11][MAXN];
int hash1[11][MAXN],hash2[11][MAXN],bas1[MAXN],bas2[MAXN];
int pos[11][MAXN];
bool C(int x,int y)
{
    int last1=-1,last2=-1;
    for(int i=1;i<=m;i++)
    {
        int h1=(hash1[i][pos[i][x]+y-1]-1LL*hash1[i][pos[i][x]-1]*bas1[y]%MOD1+MOD1)%MOD1;
        int h2=(hash2[i][pos[i][x]+y-1]-1LL*hash2[i][pos[i][x]-1]*bas2[y]%MOD2+MOD2)%MOD2;
        if(i==1) {last1=h1; last2=h2;}
        else
        {
            if(h1!=last1) return false;
            if(h2!=last2) return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            pos[i][a[i][j]]=j;
        }
    }
    bas1[0]=bas2[0]=1;
    for(int i=1;i<=n;i++)
    {
        bas1[i]=1LL*bas1[i-1]*BASE1%MOD1;
        bas2[i]=1LL*bas2[i-1]*BASE2%MOD2;
    }
    for(int i=1;i<=m;i++)
    {
        hash1[i][0]=hash2[i][0]=0;
        for(int j=1;j<=n;j++)
        {
            hash1[i][j]=(1LL*hash1[i][j-1]*BASE1+a[i][j])%MOD1;
            hash2[i][j]=(1LL*hash2[i][j-1]*BASE2+a[i][j])%MOD2;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int cur=MAXN;
        for(int j=1;j<=m;j++) cur=min(cur,n-pos[j][i]+1);
        int l=0,r=cur+1;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(C(i,mid)) l=mid; else r=mid;
        }
        ans+=l;
    }
    printf("%lld\n",ans);
    return 0;
}