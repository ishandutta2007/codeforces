#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 8000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,q,a[MAXN],tot;
int trie[MAXM][2],root[MAXN],sz[MAXM];
int newnode()
{
    ++tot;
    trie[tot][0]=trie[tot][1]=0;
    return tot;
}
void insert(int u,int v,int x)
{
    int now1=root[u]=newnode(),now2=root[v];
    for(int i=29;i>=0;i--)
    {
        int id=(x>>i)&1;
        trie[now1][id]=newnode();
        trie[now1][!id]=trie[now2][!id];
        now1=trie[now1][id];now2=trie[now2][id];
        sz[now1]=sz[now2]+1;
    }
}
vector<P> save;
int calc(int now1,int now2)
{
    int s=sz[trie[now1][0]]-sz[trie[now2][0]];
    for(auto p:save) s+=sz[trie[p.F][0]]-sz[trie[p.S][0]];
    return s;
}
int query(int l,int r)
{
    save.clear();
    int res=0;
    int now1=root[r],now2=root[l-1];
    for(int i=29;i>=0;i--)
    {
        int tmp=calc(now1,now2);
        if(tmp<2)
        {
            res+=(1<<i);
            int x=-1,y=-1;
            if(tmp==1) 
            {
                if(sz[trie[now1][0]]-sz[trie[now2][0]]) 
                {
                    x=trie[now1][0]; y=trie[now2][0];
                }
                else
                {
                    for(auto p:save)
                    {
                        if(sz[trie[p.F][0]]-sz[trie[p.S][0]])
                        {
                            x=trie[p.F][0]; y=trie[p.S][0];
                            break;
                        }
                    }
                }
            }
            for(auto &p:save)
            {
                p.F=trie[p.F][1];
                p.S=trie[p.S][1];
            }
            now1=trie[now1][1];now2=trie[now2][1];
            if(x!=-1) save.push_back(P(x,y));
        }
        else
        {
            for(auto &p:save)
            {
                p.F=trie[p.F][0];
                p.S=trie[p.S][0];
            }
            now1=trie[now1][0];now2=trie[now2][0];
        }
    }
    return res;
}
void clear()
{
    for(int i=1;i<=tot;i++) trie[i][0]=trie[i][1]=sz[i]=0;
    tot=0;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        root[0]=newnode();
        for(int i=1;i<=n;i++) insert(i,i-1,a[i]);
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",query(l,r));
        }
    }
    return 0;
}