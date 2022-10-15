/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-17 17:25:23
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,r,c,a[MAXN][MAXN],res[MAXN][MAXN];
int inv[MAXN*MAXN];
int rsum1,rsum0,csum1,csum0;
struct node
{
    int val,x,y;
    const bool operator< (node &rhs) const
    {
        return val<rhs.val;
    }
}xlz[MAXN*MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    inv[1]=1;
    for(int i=2;i<=1000000;i++)
        inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
    int tot=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            ++tot;
            xlz[tot].x=i;xlz[tot].y=j;xlz[tot].val=a[i][j];
        }
    sort(xlz+1,xlz+tot+1);
    scanf("%d%d",&r,&c);
    int ans=0,cnt=0,last;
    for(int i=1;i<=tot;i=last+1)
    {
        last=i;while(last<tot&&xlz[last].val==xlz[last+1].val) last++;
        for(int j=i;j<=last;j++)
        {
            int now=(1LL*cnt*xlz[j].x*xlz[j].x+1LL*cnt*xlz[j].y*xlz[j].y)%MOD;
            now=now+rsum1;if(now>=MOD) now-=MOD;
            now=now+csum1;if(now>=MOD) now-=MOD;
            now=(now-2LL*rsum0*xlz[j].x)%MOD;if(now<0) now+=MOD;
            now=(now-2LL*csum0*xlz[j].y)%MOD;if(now<0) now+=MOD;
            res[xlz[j].x][xlz[j].y]=1LL*(now+ans)*inv[cnt]%MOD;
            if(r==xlz[j].x&&c==xlz[j].y)
            {
                printf("%d\n",res[r][c]);
                return 0;
            }
        }
        for(int j=i;j<=last;j++)
        {
            rsum0+=xlz[j].x;if(rsum0>=MOD) rsum0-=MOD;
            csum0+=xlz[j].y;if(csum0>=MOD) csum0-=MOD;
            rsum1=(rsum1+1LL*xlz[j].x*xlz[j].x)%MOD; 
            csum1=(csum1+1LL*xlz[j].y*xlz[j].y)%MOD;
            ans+=res[xlz[j].x][xlz[j].y];
            if(ans>=MOD) ans-=MOD;
        }
        cnt+=last-i+1;
        //printf("%d %d %d %d\n",i,last,cnt,ans);
    }
    return 0;
}