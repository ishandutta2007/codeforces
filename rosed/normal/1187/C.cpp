#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=5e5+10,mod=1e9+7,inv2=5e8+4,inf=1e18;
    const double pi=acos(-1.0);
    int n,m;
    int a[N];
    int num1,num2;
    struct node
    {
        int l,r;
        inline bool operator <(const node &t) const
        {
            return l<t.l;
        }
    }q1[N],q2[N];
    bool vis[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=m;++i)
        {
            int opt;cin>>opt;
            if(opt==1)
            {
                ++num1;
                cin>>q1[num1].l>>q1[num1].r;
            }
            else
            {
                ++num2;
                cin>>q2[num2].l>>q2[num2].r;
            }
        }
        sort(q1+1,q1+num1+1);
        sort(q2+1,q2+num2+1);
        bool flag=0;
        for(int t=1;t<=num1;++t)
        {
            int l=q1[t].l,r=q1[t].r;
            for(int i=l;i<r;++i) vis[i]=1;
        }
        for(int t=1;t<=num2;++t)
        {
            int l=q2[t].l,r=q2[t].r;
            bool qwq=1;
            for(int i=l;i<r;++i)
            {
                qwq&=vis[i];
            }
            if(qwq) flag=1;
        }
        if(flag) cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            a[1]=2*n;
            for(int i=1;i<n;++i)
            {
                if(vis[i]) a[i+1]=a[i]+1;
                else a[i+1]=a[i]-1;
            }
            for(int i=1;i<=n;++i) cout<<a[i]<<' ';
            cout<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
aab

*/