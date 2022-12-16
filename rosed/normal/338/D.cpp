#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int __int128
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=2e6+10,inf=2e9;
    long long n,m,k;
    int ans1,ans2;
    long long b[N];
    int a[N],p[N];
    inline void exgcd(int a,int b,int &x,int &y,int &g)
    {
        if(!b){x=1,y=0,g=a;return;}
        exgcd(b,a%b,y,x,g);
        y-=a/b*x;
    }
    inline int lcm(int a,int b)
    {
        return a/__gcd(a,b)*b;
    }
    inline int excrt(int *a,int *p)
    {
        int ret=a[1],mod=p[1];
        for(int i=2;i<=k;++i)
        {
            //ret+p1*k1=a2+p2*k2
            //p1*k1-p2*k2=a2-ret
            int x0,y0,g;
            exgcd(mod,p[i],x0,y0,g);
            if((a[i]-ret)%g)
            {
                cout<<"NO\n";
                exit(0);
            }
            int tmp=p[i]/g;
            x0=x0*((a[i]-ret)/g)%tmp;
            ret+=x0*mod;
            mod=lcm(mod,p[i]);
            ret%=mod;
        }
        if(ret<=0) ret+=mod;
        return ret;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m>>k;
        for(int i=1;i<=k;++i) cin>>b[i];
        for(int i=1;i<=k;++i) a[i]=0,p[i]=b[i];
        ans1=excrt(a,p);
        for(int i=1;i<=k;++i) a[i]=1-i,p[i]=b[i];
        ans2=excrt(a,p);
        //cout<<(long long)ans1<<' '<<(long long)ans2<<"!!"<<endl;
        if(ans1>n||ans2>m-k+1||ans1<1||ans2<1) cout<<"NO\n";
        else
        {
            for(int i=1;i<=k;++i) a[i-1]=b[i];
            for(int i=ans2;i<=ans2+k-1;++i)
            {
                if(__gcd(ans1,i)!=a[i-ans2])
                {
                    cout<<"NO\n";
                    return;
                }
            }
            cout<<"YES\n";
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
10 20
792708224 4633945 600798790 384332600 283309209 762285205 750900274 160512987 390669628 205259431
1
7 10

*/