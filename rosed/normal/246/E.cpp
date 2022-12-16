#include<bits/stdc++.h>
using namespace std;
namespace red{
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e5+10,mod=1e9+7,inf=2e9;
    int n,m,rrt;
    string s;
    int num,tpos=1;
    map<string,int> hs;
    vector<int> eg[N];
    typedef pair<int,int> pr;
    vector<pr> q[N];
    int ret[N];
    int col[N];
    int dep[N],f[N];
    int rt[N];
    struct segment_tree
    {
        set<int> ans[N*19];
        set<int>::iterator it;
        int son[N*19][2],id[N*19];
        int tot,idx;
        inline void update(int pos,int l,int r,int &p,int k)
        {
            if(!p) p=++tot;
            if(l==r)
            {
                if(!id[p]) id[p]=++idx;
                ans[id[p]].insert(k);
                return;
            }
            if(pos<=mid) update(pos,l,mid,son[p][0],k);
            else update(pos,mid+1,r,son[p][1],k);
        }
        inline void merge(int l,int r,int &x,int &y)
        {
            //cout<<l<<' '<<r<<"----"<<endl;
            if(!x||!y) {x=x|y;return;}
            if(l==r)
            {
                if(ans[id[x]].size()<ans[id[y]].size()) swap(id[x],id[y]);
                it=ans[id[y]].begin();
                //cout<<ans[x].size()<<"!!!"<<endl;
                while(it!=ans[id[y]].end())
                {
                    ans[id[x]].insert(*it);
                    ++it;
                }
                ans[id[y]].clear();
                //cout<<ans[x].size()<<' '<<l<<' '<<r<<"!!"<<endl;
                return;
            }
            merge(l,mid,son[x][0],son[y][0]);
            merge(mid+1,r,son[x][1],son[y][1]);
        }
        inline int query(int pos,int l,int r,int p)
        {
            //cout<<pos<<"!!"<<endl;
            if(l==r) return ans[id[p]].size();
            if(pos<=mid) return query(pos,l,mid,son[p][0]);
            return query(pos,mid+1,r,son[p][1]);
        }
    }T;
    inline void dfs(int now,int fa)
    {
        dep[now]=dep[fa]+1;
        T.update(dep[now],1,n,rt[now],col[now]);
        //cout<<now<<"!!!!!!!"<<endl;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs(t,now);
            T.merge(1,n,rt[now],rt[t]);
        }
        for(pr tmp:q[now])
        {
            int t=tmp.first,id=tmp.second;
            if(dep[now]+t<=n) ret[id]=T.query(dep[now]+t,1,n,rt[now]);
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>s;
            int x;cin>>x;
            f[i]=x;
            if(!hs[s]) hs[s]=++num;
            col[i]=hs[s];
            if(!x) continue;
            eg[x].emplace_back(i);
            eg[i].emplace_back(x);
        }
        cin>>m;
        for(int i=1;i<=m;++i)
        {
            int x,y;
            cin>>x>>y;
            q[x].emplace_back(pr(y,i));
        }
        for(int i=1;i<=n;++i)
        {
            if(f[i]==0) dfs(i,0);
        }
        for(int i=1;i<=m;++i) cout<<ret[i]<<'\n';
    }
}
signed main()
{
    //freopen("data.in","r",stdin);
    //freopen("red.out","w",stdout);
    red::main();
    return 0;
}
/*
6
valera 0
valera 1
valera 1
gerald 0
valera 4
kolya 4
7
1 1
1 2
2 1
2 2
4 1
5 1
6 1

*/