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
    const int N=2e6+10,mod=(1<<20),inf=2e9;
    int n,m;
    int b[N];
    int s[N];
    int ans[N];
    inline int C(int n,int m)
    {
        if(n<m) return 0;
        int s1=s[n],s2=s[n-m]+s[m];
        if(s1>s2) return 0;
        return 1;
    }
    typedef pair<int,int> pr;
    map<pr,int> q;
    inline int work(int n,int m)
    {
        m=max(0ll,m);
        if(n<m) return 0;
        //cout<<n<<' '<<m<<"!!!!!!!!"<<endl;
        if(q[pr(n,m)]) return q[pr(n,m)];
        int s=0;
        for(int k=m;k<=n;++k) s+=C(n,k);
        if(s%2==0) s=2;
        else s=1;
        return (q[pr(n,m)]=s);
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;++m;
        for(int i=2;i<=n;i*=2)
        {
            for(int j=1;i*j<=n;++j)
            {
                ++s[i*j];
            }
        }
        for(int i=1;i<=n;++i) s[i]+=s[i-1];
        for(int i=1;i<=n;++i)
        {
            cin>>b[i];
        }
        for(int l=1;l<=n;++l)
        {
            int r=l,k=b[l];
            while(k<mod)
            {
                int tmp=work(n-1-(r-l+2)+(l==1)+(r==n),m-1-2+(l==1)+(r==n));
                //if(r-l+1==3)cout<<l<<' '<<r<<' '<<tmp<<"!!"<<endl;
                //cout<<n-1-(r-l+2)+2*(l==1)+2*(r==n)<<' '<<m-1-2+2*(l==1)+2*(r==n)<<' '<<k<<"!!!"<<endl;
                if(tmp%2==1) ans[k]^=1;
                ++r;
                if(b[r]>=20||r>n) break;
                int op=(1<<b[r]);
                k*=op;
            }
        }
        bool flag=0;
        for(int i=mod-1;i>=0;--i)
        {
            if(ans[i]==1||i==0) flag=1;
            if(flag) cout<<ans[i];
        }
        cout<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
10 3
1 1 1 1 1 1 1 1 1 1

*/