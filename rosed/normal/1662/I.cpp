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
    const int N=2e6+10,mod=998244353,inf=2e9;
    int n,m,num;
    int a[N],s[N];
    int p[N];
    struct node
    {
        double pos;
        int val;
        inline bool operator < (const node &t) const
        {
            return pos<t.pos;
        }
    }c[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T=1;
        while(T--)
        {
            int n,m;cin>>n>>m;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
            }
            for(int i=1;i<=m;++i)
            {
                cin>>p[i];
            }
            sort(p+1,p+m+1);
            p[m+1]=inf;
            for(int i=1;i<=n;++i)
            {
                int pos=(i-1)*100;
                int t=lower_bound(p+1,p+m+1,pos)-p;
                double len=p[t]-pos;
                if(t>1) len=min(len,(double)(pos-p[t-1]));
                c[++num]=(node){pos-len+0.01,a[i]};
                c[++num]=(node){pos+len,-a[i]};
            }
            sort(c+1,c+num+1);

           //for(int i=1;i<=num;++i) cout<<c[i].pos<<' '<<c[i].val<<"!!"<<endl;
            int ans=0,sum=0;
            for(int i=1;i<=num;++i)
            {
                int j=i;
                while(c[j].pos==c[i].pos&&j<=num)
                {
                    sum+=c[j].val;
                    ++j;
                }
                --j;
                i=j;
                //cout<<c[i].pos<<"!!!"<<endl;
                //cout<<sum<<' '<<j<<"!!"<<endl;
                ans=max(ans,sum);
            }
            cout<<ans<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
3 3
5 10 12
300 50 50

*/