/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-28 19:22:22
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
int a[MAXN],dp[MAXN];
struct node
{
    int l,r,inc;
};
node upd[MAXN];
bool valid[MAXN];
bool cmp(node x,node y)
{
    if(x.l!=y.l) return x.l<y.l;
    return x.r<y.r;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<q;i++)
        scanf("%d%d%d",&upd[i].l,&upd[i].r,&upd[i].inc);
    sort(upd,upd+q,cmp);
    dp[0]=INF;
    memset(valid,false,sizeof(valid));
    for(int i=0;i<q;i++)
    {
        for(int j=n;j>=upd[i].inc;j--)
        {
            dp[j]=max(dp[j],min(upd[i].r,dp[j-upd[i].inc]));
            if(dp[j]>=upd[i].l) valid[j]=true;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++) if(valid[i]) cnt++;
    printf("%d\n",cnt);
    for(int i=1;i<=n;i++) if(valid[i]) printf("%d ",i);
    return 0;
}