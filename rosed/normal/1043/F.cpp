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
    const int N=300010,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n;
    vector<int> gcdmul(vector<int> a,vector<int> b)
    {
        int n=a.size();
        for(int i=1;i<N;++i)
        {
            for(int j=2*i;j<N;j+=i)
            {
                a[i]+=a[j];
                b[i]+=b[j];
            }
        }
        vector<int> c(N);
        for(int i=1;i<=n;++i) c[i]=a[i]*b[i];
        for(int i=N-1;i;--i)
        {
            for(int j=2*i;j<N;j+=i)
            {
                c[i]-=c[j];
            }
        }
        return c;
    }
    void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        vector<int> a(N),b(N);
        int g;
        for(int i=1;i<=n;++i)
        {
            int x;cin>>x;
            b[x]=a[x]=1;
            if(i==1) g=x;
            else g=__gcd(g,x);
        }
        if(g!=1)
        {
            cout<<-1<<'\n';
            return;
        }
        int ans=1;
        while("qwq")
        {
            if(b[1]) break;
            b=gcdmul(a,b);
            ++ans;
        }
        cout<<ans<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
7 2 4 12
7 -5 2 8
7 -5 8 2
*/