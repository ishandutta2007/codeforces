#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        string s;cin>>s;
        int n;n=s.length();
        vector<int> a(n+1);
        for(int i=1;i<=n;++i)
        {
            a[i]=s[i-1]-'0';
            a[i]+=a[i-1];
        }
        int w,m;
        cin>>w>>m;
        vector<vector<int> > pos(9);
        typedef array<int,2> pr;
        for(int i=w;i<=n;++i)
        {
            int tmp=a[i]-a[i-w];
            pos[tmp%9].emplace_back(i-w+1);
        }
        for(int i=1;i<=m;++i)
        {
            int l,r,k;
            cin>>l>>r>>k;
            int tt=a[r]-a[l-1];
            pr ans={inf,inf};
            tt%=9;
            for(int t1=0;t1<9;++t1)
            {
                for(int t2=0;t2<9;++t2)
                {
                    if(!pos[t1].size()||!pos[t2].size()) continue;
                    if(t1==t2&&pos[t1].size()<=1) continue;
                    if((t1*tt+t2)%9!=k) continue;
                    pr pp;
                    pp[0]=pos[t1][0];
                    if(t1==t2) pp[1]=pos[t1][1];
                    else pp[1]=pos[t2][0];
                    ans=min(ans,pp);
                }
            }
            if(ans[0]==inf) ans={-1,-1};
            cout<<ans[0]<<' '<<ans[1]<<'\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
m/i=(-p%i)*inv[i]

inv[i]*i%p=1

*/