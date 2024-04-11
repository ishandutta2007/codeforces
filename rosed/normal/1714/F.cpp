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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,a,b,c;
    int st[N][2],top;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n>>a>>b>>c;
            int idx=3;
            int len=-1,s=0;
            for(int i=0;i<=b;++i)
            {
                int jie=b-i;
                if(jie>a) continue;
                if(i+a-jie==c&&i+a<n)
                {
                    len=a-jie;
                    s=i;break;
                }
            }
            if(len==-1){ cout<<"NO\n";continue;}
            cout<<"YES\n";
            int pre=1,jie=len;
            if(jie==a)
            {
                for(int i=1;i<a;++i)
                {
                    cout<<pre<<' '<<++idx<<'\n';
                    pre=idx;
                }
                cout<<pre<<' '<<2<<'\n';
                pre=2;
                for(int i=1;i<s;++i)
                {
                    cout<<pre<<' '<<++idx<<'\n';
                    pre=idx;
                }
                cout<<pre<<' '<<3<<'\n';
                while(idx<n)
                {
                    cout<<++idx<<' '<<1<<'\n';
                }
            }
            else
            {
                if(s==0)
                {
                    pre=1;
                    for(int i=1;i<c;++i)
                    {
                        cout<<pre<<' '<<++idx<<'\n';
                        pre=idx;
                    }
                    cout<<pre<<' '<<3<<'\n';
                    pre=3;
                    for(int i=c+1;i<a;++i)
                    {
                        cout<<pre<<' '<<++idx<<'\n';
                        pre=idx;
                    }
                    cout<<pre<<' '<<2<<'\n';

                    while(idx<n)
                    {
                        cout<<++idx<<' '<<1<<'\n';
                    }
                }
                else
                {
                    for(int i=1;i<=jie;++i)
                    {
                        cout<<pre<<' '<<++idx<<'\n';
                        pre=idx;
                    }
                    int ppre=pre;
                    for(int i=1;i<s;++i)
                    {
                        cout<<pre<<' '<<++idx<<'\n';
                        pre=idx;
                    }
                    cout<<pre<<' '<<3<<'\n';
                    pre=ppre;
                    for(int i=jie+1;i<a;++i)
                    {
                        cout<<pre<<' '<<++idx<<'\n';
                        pre=idx;
                    }
                    cout<<pre<<' '<<2<<'\n';
                    while(idx<n)
                    {
                        cout<<++idx<<' '<<1<<'\n';
                    }
                }
                
            }
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
4 1 3 4


*/