#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int last[MAXN],prelast[MAXN],dp[MAXN];
const int blocks=400;
const int blocknum=300;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int sum[blocknum];
int shift[blocknum];
int res[blocknum][blocks];
int cnt[blocknum][2*MAXN];
int origin;
void point_modify(int pos,int v)
{
    int b=(pos-1)/blocks+1;
    int obj=res[b][pos%blocks]+shift[b];
    res[b][pos%blocks]+=v;
    dec(cnt[b][origin+obj-shift[b]],dp[pos]);add(cnt[b][origin+obj-shift[b]+v],dp[pos]);
    if(obj==k&&v>0) dec(sum[b],dp[pos]);
    else if(obj==k+1&&v<0) add(sum[b],dp[pos]);
}
void block_modify(int id,int v)
{
    if(v>0) dec(sum[id],cnt[id][origin+k-shift[id]]);
    else add(sum[id],cnt[id][origin+k+1-shift[id]]);
    shift[id]+=v;
}
int point_query(int pos)
{
    int b=(pos-1)/blocks+1;
    if(res[b][pos%blocks]+shift[b]<=k) return dp[pos]; else return 0;
}
int block_query(int id)
{
    return sum[id];
}
void modify(int l,int r,int x)
{
    //printf("%d %d %d\n",l,r,x);
    while(l<=r&&r%blocks!=0) point_modify(r,x),r--;
    while(l<=r&&l%blocks!=1) point_modify(l,x),l++;
    while(l<=r)
    {
        int b=(l-1)/blocks+1;
        block_modify(b,x);
        l+=blocks;
    }
}
int query(int l,int r)
{
    int ans=0;
    while(l<=r&&r%blocks!=0) add(ans,point_query(r)),r--;
    while(l<=r&&l%blocks!=1) add(ans,point_query(l)),l++;
    while(l<=r) 
    {
        int b=(l-1)/blocks+1;
        add(ans,block_query(b));
        l+=blocks;
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&k);origin=n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[1]=1;cnt[1][origin]=1;sum[1]=1;   
    for(int i=1;i<=n;i++)
    {
        modify(last[a[i]]+1,i,1);
        if(prelast[a[i]]<last[a[i]]) modify(prelast[a[i]]+1,last[a[i]],-1);
        prelast[a[i]]=last[a[i]];last[a[i]]=i;
        dp[i+1]=query(1,i);
        add(sum[i/blocks+1],dp[i+1]);add(cnt[i/blocks+1][origin-shift[i/blocks+1]],dp[i+1]);
    }
    printf("%d\n",dp[n+1]);
    return 0;
}