#include<bits/stdc++.h>
#define int long long
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int n,x[MAXN],d[MAXN];
int pre[MAXN],suf[MAXN];
vector<int> pos;
vector<int> del[MAXN];
multiset<int> s;
vector<int> dis;
int sz,bit[2*MAXN+1];
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
    while(i<=sz)
    {
        bit[i]=max(bit[i],x);
        i+=i&-i;
    }
}
signed main()
{
    scanf("%lld",&n);
    for(int i=0;i<=n+1;i++) 
    {
        scanf("%lld",&x[i]);
        pos.push_back(x[i]);
    }
    for(int i=1;i<=n;i++) scanf("%lld",&d[i]);
    s.insert(0);
    for(int i=1;i<=n;i++)
    {
        for(auto x:del[i]) s.erase(s.find(x));
        int p=*(--s.end());
        pre[i]=2*d[i]-(x[i]-p);
        if(pre[i]>=0)
        {
            s.insert(x[i]);
            int id=upper_bound(pos.begin(),pos.end(),x[i]+pre[i])-pos.begin();
            del[id].push_back(x[i]);
        }
        if(pre[i]>=(x[n+1]-x[i]))
        {
            puts("0");
            return 0;
        }
    }
    s.clear();
    for(int i=1;i<=n;i++) del[i].clear();
    s.insert(x[n+1]);
    for(int i=n;i>=1;i--)
    {
        for(auto x:del[i]) s.erase(s.find(x));
        int p=*s.begin();
        suf[i]=2*d[i]-(p-x[i]);
        if(suf[i]>=0)
        {
            s.insert(x[i]);
            int id=lower_bound(pos.begin(),pos.end(),x[i]-suf[i])-pos.begin();
            if(id) del[id-1].push_back(x[i]);
        }
    }
    int ans=x[n+1]-x[0];
    for(int i=1;i<=n;i++)
    {
        if(pre[i]>0) ans=min(ans,x[n+1]-x[i]);
        if(suf[i]>0) ans=min(ans,x[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(pre[i]>0) dis.push_back(x[i]+pre[i]);
        if(suf[i]>0) dis.push_back(x[i]-suf[i]);
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    sz=(int)dis.size();
    for(int i=1;i<=sz;i++) bit[i]=-INF;
    for(int i=1;i<=n;i++)
    {
        if(suf[i]>0)
        {
            int id=lower_bound(dis.begin(),dis.end(),x[i]-suf[i])-dis.begin()+1;
            int val=sum(sz+1-id);
            if(val!=-INF) ans=min(ans,x[i]-val);
        }
        if(pre[i]>0)
        {
            int id=lower_bound(dis.begin(),dis.end(),x[i]+pre[i])-dis.begin()+1;
            add(sz+1-id,x[i]);
        }
    }
    printf("%.10f\n",ans/2.0);
    return 0;
}