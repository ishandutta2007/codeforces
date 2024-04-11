#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    int n,r,k;
    int a[N],s[N],b[N];
    int c[N];
    inline bool check(int x)
    {
        int m=k;
        for(int i=1;i<=n+1;++i) c[i]=0;
        for(int i=1;i<=n;++i)
        {
            c[i]+=c[i-1];
            if(b[i]+c[i]<x)
            {
                int y=x-b[i]-c[i];
                //if(x==10) cout<<i<<"!!!!!!!"<<endl;
                if(y>m) return 0;
                m-=y;
                int rr=min(n,i+2*r);
                //if(x==10) cout<<i<<' '<<rr<<"!!"<<endl;
                c[i]+=y;
                c[rr+1]-=y;
            }
        }
        return 1;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>r>>k;
        int ql=inf*inf,qr=4e18;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            s[i]=s[i-1]+a[i];
        }
        for(int i=1;i<=n;++i)
        {
            int ll=max(1ll,i-r);
            int rr=min(n,i+r);
            b[i]=s[rr]-s[ll-1];
            ql=min(ql,b[i]);
            //cout<<l<<' '<<b[i]<<"!!!!!!!!!!"<<endl;
        }
       // cout<<l<<"!!!"<<endl;
        while(ql<=qr)
        {
            int mid=(ql+qr)>>1;
            if(check(mid)) ql=mid+1;
            else qr=mid-1;
        }
        cout<<ql-1<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
4 2 3
1 2 6 9


*/