#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM (1<<15)
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct node
{
    int id,num,to;
};
int k;
ll sum;
vector<int> v[MAXN];
vector<node> ret[MAXN];
int where[MAXN];
ll res[MAXN];
bool dp[MAXM];
bool good[MAXM];
bool vis[20];
vector<ll> dis;
vector<int> valid;
P ans[MAXN];
int find_cycle(int from,int num)
{
    vector<node> tmp;
    memset(vis,false,sizeof(vis));
    vis[from]=true;
    int mask=(1<<(from-1)),now=from,val=num;
    do
    {
        ll need=sum-res[now]+val;
        int id=lower_bound(dis.begin(),dis.end(),need)-dis.begin();
        if(id>=(int)dis.size()||(dis[id]!=need)) return -1;
        tmp.push_back((node){where[id],need,now});
        if(vis[where[id]]&&where[id]!=from) return -1;
        if(vis[where[id]]) 
        {
            if(need!=num) return -1;
            break;
        }
        if(!vis[where[id]])
        {
            val=need;
            now=where[id];
            vis[now]=true;
            mask|=(1<<(now-1));
        }
    }while(true);
    good[mask]=true;
    ret[mask]=tmp;
    return mask;
}
int main()
{
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;j++)
        {
            int y;
            scanf("%d",&y);
            v[i].push_back(y);
            dis.push_back(y);
            res[i]+=y; sum+=y;
        }
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    for(int i=1;i<=k;i++)
        for(auto x:v[i])
        {
            int id=lower_bound(dis.begin(),dis.end(),x)-dis.begin();
            where[id]=i;
        }
    memset(dp,false,sizeof(dp));
    if(sum%k) {puts("No"); return 0;}
    sum/=k;
    for(int i=1;i<=k;i++)
        for(auto x:v[i])
            find_cycle(i,x);
    dp[0]=true;
    for(int i=0;i<(1<<k);i++)
    {
        if(!dp[i]) continue;
        int sup=(1<<k)-1-i,sub=sup;
        do
        {
            if(good[sub]) dp[i^sub]=true;
            sub=(sub-1)&sup;
        }while(sub!=sup);
    }
    if(!dp[(1<<k)-1]) {puts("No"); return 0;}
    puts("Yes");
    int curmask=(1<<k)-1;
    while(curmask)
    {
        int sup=curmask,sub=sup;
        do
        {
            if(good[sub]&&dp[curmask^sub])
            {
                for(auto p:ret[sub]) ans[p.id]=P(p.num,p.to);
                curmask^=sub;
                break;
            }
            sub=(sub-1)&sup;
        }while(sub!=sup);
    }
    for(int i=1;i<=k;i++) printf("%d %d\n",ans[i].F,ans[i].S);
    return 0;
}