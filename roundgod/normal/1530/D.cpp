#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],b[MAXN];
set<int> pos[MAXN];
set<int> s1,s2;
set<int> inter;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) pos[i].clear();
        s1.clear(); s2.clear(); inter.clear();
        for(int i=1;i<=n;i++) s2.insert(i);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            pos[a[i]].insert(i);
        }
        int lucky=-1;
        for(int i=1;i<=n;i++) if(!pos[i].size()) lucky=i;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(pos[i].size())
            {
                int x;
                if(pos[i].count(lucky)) x=lucky; else x=*pos[i].begin();
                ans++;
                b[x]=i;
                pos[i].erase(x);
                s2.erase(i);
            }
        }
        for(int i=1;i<=n;i++) 
            for(auto x:pos[i])
            {
                s1.insert(x);
                if(s2.count(x)) inter.insert(x);
            }
        assert(s1.size()==s2.size());
        while(s1.size())
        {
            if(inter.size())
            {
                assert(s2.size()>1);
                int x=*inter.begin();
                int id=-1;
                for(auto y:s2) if(y!=x) {id=y; break;}
                b[x]=id;
                s1.erase(x); s2.erase(id);
                inter.erase(x);
                if(inter.count(id)) inter.erase(id);
            }
            else
            {
                int x=*s1.begin(),y=*s2.begin();
                b[x]=y;
                s1.erase(x); s2.erase(y);
            }
        }        
        printf("%d\n",ans);
        for(int i=1;i<=n;i++) printf("%d%c",b[i],i==n?'\n':' ');
    }
    return 0;
}