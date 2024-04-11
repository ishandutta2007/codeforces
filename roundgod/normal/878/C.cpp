#include<bits/stdc++.h>
#define MAXN 100005
#define MAXK 10
using namespace std;
int n,k;
struct scc
{
    int low[MAXK],high[MAXK],sz;
    scc()
    {
        sz=1;
        for(int i=0;i<k;i++)
        {
            int p;
            scanf("%d",&p);
            low[i]=p;
            high[i]=p;
        }
    }
    bool operator<(const scc &x)const
    {
        for(int i=0;i<k;i++)
            if(high[i]>=x.low[i]) return false;
        return true;
    }
    void merge(const scc &x)
    {
        sz+=x.sz;
        for(int i=0;i<k;i++)
        {
            low[i]=min(low[i],x.low[i]);
            high[i]=max(high[i],x.high[i]);
        }
    }
};
set<scc> s;
int main()
{
    scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
    {
        scc q=scc();
        auto lb=s.lower_bound(q),ub=s.upper_bound(q);
        while(lb!=ub)
        {
            q.merge(*lb);
            lb=s.erase(lb);
        }
        s.insert(q);
        printf("%d\n",(s.rbegin())->sz);
    }
    return 0;
}