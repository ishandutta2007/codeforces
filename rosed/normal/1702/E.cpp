#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
const int N=5e5+10,mod=1e9+7;
int n,m;
struct node
{
    int x,y;
}a[N];
int s[N],col[N];
vector<int> eg[N];
inline bool dfs(int now,int c)
{
    col[now]=c;
    for(int t:eg[now])
    {
        if(!col[t]) dfs(t,c^1);
        else if(col[t]==c) return 0;
    }
    return 1;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int qwq;cin>>qwq;
    while(qwq--)
    {
        cin>>n;
        for(int i=1;i<=n;++i) s[i]=0,eg[i].clear(),col[i]=0;
        bool flag=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i].x>>a[i].y;
            if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
            if(++s[a[i].x]>2) flag=1;
            if(++s[a[i].y]>2) flag=1;
        }
        if(flag)
        {
            cout<<"NO\n";
            continue;
        }
        for(int i=1;i<=n;++i)
        {
            eg[a[i].x].emplace_back(a[i].y);
            eg[a[i].y].emplace_back(a[i].x);
        }
        for(int i=1;i<=n;++i)
        {
            if(col[i]) continue;
            if(!dfs(i,2)) {flag=1;break;}
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
/*
1
6
1 2
4 5
1 3
4 6
2 3
5 6

*/