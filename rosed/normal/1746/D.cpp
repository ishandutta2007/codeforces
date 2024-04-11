#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit ((i)&(-i))
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > eg(n+1);
    for(int i=2;i<=n;++i)
    {
        int x;cin>>x;
        eg[x].emplace_back(i);
    }
    vector<int> val(n+1);
    for(int i=1;i<=n;++i) cin>>val[i];
    int ans=0;
    vector<int> ey(n+1);
    function<void(int,int,int)> dfs=[&](int now,int fa,int m) -> void
    {
        vector<int> tmp;
        int str=eg[now].size();
        ans+=m*val[now];
        for(int t:eg[now])
        {
            dfs(t,now,m/str);

            tmp.emplace_back(ey[t]+val[t]);
        }
        // cout<<now<<' '<<ans<<"!!"<<endl;
        if(!tmp.size()) return;
        int num=tmp.size();
        sort(tmp.begin(),tmp.end());
        reverse(tmp.begin(),tmp.end());
        int ee=m%num;
        ey[now]=tmp[ee];
        // cout<<now<<' '<<ey[now]<<' '<<ee<<' '<<tmp[0]<<"!!!"<<endl;
        int eee=m%str;
        for(int i=0;i<eee;++i) ans+=tmp[i];
    };
    dfs(1,0,m);
    cout<<ans<<'\n';
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}