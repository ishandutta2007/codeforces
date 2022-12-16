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
    const int N=2e5+10,mod=998244353,inv2=5e8+4,inf=2e9;
    int fast(int x,int k)
    {
        int ret=1;
        while(k)
        {
            if(k&1) ret=ret*x%mod;
            x=x*x%mod;
            k>>=1;
        }
        return ret;
    }
    inline void main()
    {
        int n,m;
        cin>>n;
        vector a(2,vector<int>(n+2)),b(2,vector<int>(n+2)),c(2,vector<int>(n+2));
        for(int i=1;i<=n;++i)
        {
            cin>>a[0][i];
            if(i!=1) ++a[0][i];
            b[0][i]=a[0][i]-i;
            c[0][i]=a[0][i]+i;
        }
        for(int i=1;i<=n;++i)
        {
            cin>>a[1][i];
            ++a[1][i];
            b[1][i]=a[1][i]-i;
            c[1][i]=a[1][i]+i;
            
        }
        for(int i=n-1;i>=1;--i)
        {
            c[0][i]=max(c[0][i],c[0][i+1]);
            c[1][i]=max(c[1][i],c[1][i+1]);
            b[0][i]=max(b[0][i+1],b[0][i]);
            b[1][i]=max(b[1][i+1],b[1][i]);
        }
        int opt=0,ans=0,now=0;
        int t1=max(0ll,b[0][1]+1);
        now=t1+n-1;
        int t2=c[1][1]-n-1;
        t2=max(0ll,t2-now);
        now+=n+t2;
        ans=now,now=0;
        for(int i=1;i<=n;++i)
        {
            now=max(now+1,a[opt^1][i]);
            opt^=1;
            if(i==n)
            {
                ans=min(ans,now);
                break;
            }
            int tmp=now;
            //if(i==1) cout<<now<<"!!!"<<endl;
            t1=max(0ll,b[opt][i+1]+i-tmp);
            //if(i==1) cout<<t1<<"!!"<<endl;
            tmp+=t1+n-i;
            t2=max(0ll,c[opt^1][i+1]-n-1-tmp);
            //if(i==1) cout<<t2<<"!!!"<<endl;
            tmp+=t2+n-i;
            //if(i==1) cout<<tmp<<"!!!!!!"<<endl;
            ans=min(ans,tmp);
            now=max(now+1,a[opt][i+1]);
        }
        cout<<ans<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int qwq=1; cin>>qwq;
    while(qwq--)
    red::main();
    return 0;
}
/*

0 4 5

6 4 1
4+2-3=3
6+1-3=4

4-2 6-3
2 3
-1


*/