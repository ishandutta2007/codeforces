#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
const int N=5e5+10,mod=1e9+7;
int n,m;
int a[N];
vector<int> eg[N];
int dep[N];
int f[N][21];
inline void dfs(int now,int fa)
{
    dep[now]=dep[fa]+1;
    f[now][0]=fa;
    for(int i=1;i<=20;++i) f[now][i]=f[f[now][i-1]][i-1];
    for(int t:eg[now])
    {
        if(t==fa) continue;
        dfs(t,now);
    }
}
inline int query(int x,int y)
{
    for(int i=20;~i;--i)
    {
        if(dep[f[y][i]]>=dep[x]) y=f[y][i];
    }
    if(x==y) return 1;
    else return 0;
}
inline int lca(int x,int y)
{
    if(dep[x]>dep[y]) swap(x,y);
    for(int i=20;~i;--i)
    {
        if(dep[f[y][i]]>=dep[x]) y=f[y][i];
    }
    if(x==y) return x;
    for(int i=20;~i;--i)
    {
        if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}
inline bool cmp(int x,int y)
{
    return dep[x]<dep[y];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int qwq=1;
    while(qwq--)
    {
        cin>>n;
        for(int i=1;i<n;++i)
        {
            int x,y;
            cin>>x>>y;
            eg[x].emplace_back(y);
            eg[y].emplace_back(x);
        }
        dfs(1,0);
        cin>>m;
        for(int i=1;i<=m;++i)
        {
            //cout<<i<<"!!"<<endl;
            int k;
            cin>>k;
            for(int j=1;j<=k;++j) cin>>a[j];
            sort(a+1,a+k+1,cmp);
            bool flag=1;
            int op=0,op2=0;
            int st=1,ed=0;
            for(int j=1;j<=k;++j)
            {
                if(query(a[st],a[j])&&dep[a[j]]>dep[a[ed]]) ed=j;
            }
            for(int j=1;j<=k;++j)
            {
                if(!query(a[st],a[j])||!query(a[j],a[ed]))
                {
                    if(!op) op=a[j],op2=a[j];
                    else
                    {
                        int y=a[j];
                        if(dep[y]<dep[op]) swap(op,y);
                        if(dep[y]>dep[op2]) swap(op2,y);
                        if(!query(op,y)||!query(y,op2))
                        {
                            //cout<<op<<' '<<y<<"!!"<<endl;
                            flag=0;break;
                        }
                    }
                }
            }
            if(op)
            {
                op=lca(op,a[ed]);
                if(!query(op,a[1])) flag=0;
            }
            if(flag) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
/*
8
5 8
4 7
1 2
2 3
2 4
3 5
5 6
2
4
3 4 5 6
4
4 3 6 8





*/