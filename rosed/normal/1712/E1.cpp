#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n=200000,m;
        cin>>m;
        vector<int> ans(m+1);
        struct node
        {
            int l,r,id;
            bool operator < (const node &t) const
            {
                return r<t.r;
            }
        };
        vector<node> a(m+1);
        for(int i=1;i<=m;++i)
        {
            cin>>a[i].l>>a[i].r;
            a[i].id=i;
        }
        sort(a.begin()+1,a.end());
        vector<vector<int> > d(n+1);
        vector<int> tr(n+1);
        auto update=[&](int x,int k) -> void
        {
            for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=k;
        };
        auto query=[&](int x) -> int
        {
            int sum=0;
            for(int i=x;i;i-=lowbit(i)) sum+=tr[i];
            return sum;
        };
        for(int i=n;i>=1;--i)
        {
            for(int j=i+i;j<=n;j+=i)
            {
                d[j].emplace_back(i);
            }
        }
        int t=1;
        for(int i=1;i<=n;++i)
        {
            int cnt=0;
            for(int j:d[i])
            {
                update(j,cnt);
                ++cnt;
            }
            if((i*2)%12==0) update((i*2)/4,1);
            if((i*2)%30==0) update((i*2)/5,1);
            while(t<=m&&a[t].r<=i)
            {
                int len=a[t].r-a[t].l+1;
                ans[a[t].id]=len*(len-1)*(len-2)/6-(query(i)-query(a[t].l-1));
                ++t;
            }
        }
        for(int i=1;i<=m;++i) cout<<ans[i]<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/