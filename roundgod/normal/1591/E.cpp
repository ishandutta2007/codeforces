#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,q;
int a[MAXN],p[MAXN],cnt[MAXN];
vector<int> G[MAXN];
vector<pair<P,int> > query[MAXN];
int ans[MAXN];
int bit[MAXN+1];
vector<int> s[MAXN]; 
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    if(i==0) return;
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int bisearch(int v)
{
    int sum=0,pos=0;
    for(int i=MAXLOGN;i>=0;i--)
    {
        if(pos+(1<<i)<=n&&sum+bit[pos+(1<<i)]<v)
        {
            sum+=bit[pos+(1<<i)];
            pos+=(1<<i);
        }
    }
    return pos+1;
}
int get(int x)
{
    while(s[x].size()>0&&cnt[s[x].back()]!=x) s[x].pop_back();
    return s[x].back();
}
void dfs(int v)
{
    add(cnt[a[v]],-1);
    cnt[a[v]]++; 
    s[cnt[a[v]]].push_back(a[v]); add(cnt[a[v]],1);
    for(auto p:query[v])
    {
        int l=p.F.F,k=p.F.S,res;
        if(sum(n)-sum(l-1)<k) ans[p.S]=-1; 
        else ans[p.S]=get(bisearch(sum(l-1)+k));
    }
    for(auto to:G[v]) dfs(to);
    add(cnt[a[v]],-1);
    cnt[a[v]]--;
    s[cnt[a[v]]].push_back(a[v]); add(cnt[a[v]],1);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=0;i<=n;i++) G[i].clear(),query[i].clear(),s[i].clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=2;i<=n;i++) 
        {
            scanf("%d",&p[i]);
            G[p[i]].push_back(i);
        }
        for(int i=0;i<q;i++)
        {
            int v,l,k;
            scanf("%d%d%d",&v,&l,&k);
            query[v].push_back(make_pair(P(l,k),i));
        }
        dfs(1);
        for(int i=0;i<q;i++) printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}