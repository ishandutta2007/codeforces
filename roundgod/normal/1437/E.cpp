#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
using namespace std;
int bit[2*MAXN+1],n,k,a[MAXN];
bool valid[MAXN];
int dp[MAXN];
vector<int> dis;
vector<int> op;
int sum(int i)
{
    int s=-INF;
    while(i>0)
    {
        s=max(s,bit[i]);
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=MAXN)
    {
        op.push_back(i);
        bit[i]=max(bit[i],x);
        i+=i&-i;
    }
}
void rollback()
{
    for(auto x:op) bit[x]=-INF;
    op.clear();
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        dis.push_back(a[i]-i);
    }
    dis.push_back(-INF);
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    for(int i=0;i<=MAXN;i++) bit[i]=-INF;
    memset(valid,true,sizeof(valid));
    for(int i=1;i<=k;i++)
    {
        int x;
        scanf("%d",&x);
        valid[x]=false;
    }
    add(1,0);
    bool f=true;
    for(int i=1;i<=n;i++)
    {
        dp[i]=-INF;
        int id=lower_bound(dis.begin(),dis.end(),a[i]-i)-dis.begin()+1;
        int val=sum(id);
        if(val==-INF)
        {
            if(!valid[i]) {f=false; break;}
            else continue;
        }
        dp[i]=val+1;
        if(!valid[i]) rollback();
        add(id,dp[i]);
    }
    if(!f)
    {
        puts("-1");
        return 0;
    }
    int ans=-INF;
    for(int i=n;i>=1;i--)
    {
        ans=max(ans,dp[i]);
        if(!valid[i]) break;
    }
    printf("%d\n",n-ans);
    return 0;
}