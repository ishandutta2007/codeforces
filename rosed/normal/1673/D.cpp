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
    const int N=1e6+10,mod=1e9+7,inf=2e9;
    int n,m,ans;
    int a0,b0,c0,q1,q2,q3;
    inline bool checkbc()
    {
        int s=b0;
        int l=0,r=n-1,k=0;
        while(l<=r)
        {
            if(s+mid*q2<=c0) k=mid,l=mid+1;
            else r=mid-1;
        }
        if(s+k*q2!=c0) return 0;
        l=0,r=n-1,k=n-1;
        while(l<=r)
        {
            if(s+mid*q2>=c0+(m-1)*q3) k=mid,r=mid-1;
            else l=mid+1;
        }
        if(s+k*q2!=c0+(m-1)*q3) return 0;
        if(q3%q2!=0) return 0;
        return 1;
    }
    inline int lcm(int x,int y)
    {
        return x*y/__gcd(x,y);
    }
    inline void work(int l,int r,int tl,int tr,int x)
    {
        // cout<<x<<"!!"<<endl;
        //cout<<tl<<' '<<l<<"!!!"<<endl;
        int k=(tl-l)/x;
        //cout<<x<<' '<<k<<"!!"<<endl;
        ans=(ans+k*k)%mod;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>b0>>q2>>n;
            cin>>c0>>q3>>m;
            ans=0;
            if(!checkbc()||c0<b0||(c0+(m-1)*q3)>(b0+(n-1)*q2))
            {
                cout<<"0"<<'\n';
                continue;
            }
            if(c0-q3<b0||(c0+m*q3)>(b0+(n-1)*q2))
            {
                cout<<"-1\n";
                continue;
            }
            //ans=1;
            for(int q1=1;q1*q1<=q3;++q1)
            {
                if(q3%q1!=0) continue;
                int x=q1,y=lcm(x,q2);
                if(y==q3) work(c0-q3,c0+m*q3,c0,c0+(m-1)*q3,x);
                if(q1*q1==q3) continue;
                x=q3/q1,y=lcm(x,q2);
                //if(x==q3) cout<<y<<' '<<q3<<"!!!!!!!!!!!!!"<<endl;
                if(y==q3) work(c0-q3,c0+m*q3,c0,c0+(m-1)*q3,x);
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
1
-685761754 232786464 375044871
-220188826 232786464 262040392

*/