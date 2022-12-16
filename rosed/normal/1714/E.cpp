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
    int n;
    int a[N],s[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n;
            int f1=0,f2=0,f3=0;
            bool flag=0;
            int ss=-1;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                if(a[i]%10!=5&&a[i]%10!=0)
                {
                    a[i]%=20;
                    if(a[i]==3||a[i]==6||a[i]==12||a[i]==14||a[i]==18||a[i]==7||a[i]==9||a[i]==11) f2=1;
                    else f1=1;
                }
                else
                {
                    f3=1;
                    if(a[i]%10==5) a[i]+=5;
                    if(ss==-1) ss=a[i];
                    else
                    {
                        if(a[i]!=ss) flag=1;
                    }
                }
            }
            if(f1+f2+f3>1||flag) cout<<"No\n";
            else cout<<"Yes\n";
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
2
50 30

1 2 4 8
2 4 8 16 22 24 28 36 42
3 6 12 14 18 26 32 
4 8 16
5 10
6 12 
7 14 18 26
8 16
9 18
19 28
*/