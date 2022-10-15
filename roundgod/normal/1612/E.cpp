#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],k[MAXN];
int val[MAXN];
multiset<P> ms;
vector<int> ans[21];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&k[i]);
    double res=0.0;
    int id=-1;
    for(int t=1;t<=20;t++)
    {
        ms.clear();
        memset(val,0,sizeof(val));
        for(int i=1;i<=n;i++) if(k[i]<t) val[a[i]]+=k[i]; else val[a[i]]+=t;
        for(int i=1;i<=200000;i++) 
        {
            ms.insert(P(-val[i],i));
            if(ms.size()>t) ms.erase(--ms.end());
        }
        double sum=0.0;
        for(auto p:ms) {ans[t].push_back(p.S); sum-=p.F;}
        if(sum/t>res)
        {
            res=sum/t;
            id=t;
        } 
    } 
    memset(val,0,sizeof(val));
    for(int i=1;i<=n;i++) val[a[i]]+=k[i];
    ms.clear();
    for(int i=1;i<=200000;i++) ms.insert(P(-val[i],i));
    double sum=0.0;
    int tot=0;
    for(auto p:ms)
    {
        sum-=p.F;
        tot++;
        if(tot>20&&sum/tot>res)
        {
            res=sum/tot;
            id=tot;
        }
    }
    if(id<=20) 
    {
        printf("%d\n",id);
        assert(ans[id].size()==id);
        for(auto x:ans[id]) printf("%d ",x);
    }
    else
    {
        printf("%d\n",id);
        int tot=0;
        for(auto p:ms)
        {
            printf("%d ",p.S);
            tot++;
            if(tot==id) break;
        }
    }
    return 0;
}