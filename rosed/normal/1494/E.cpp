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
    const int N=1e6+10,mod=998244353,inv2=499122177,inf=2e18;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        int sum1=0,sum2=0;
        map<int,map<int,int> > q;
        for(int i=1;i<=m;++i)
        {
            char ch,t;
            int x,y;
            cin>>ch;
            if(ch=='+')
            {
                cin>>x>>y;
                cin>>t;
                q[x][y]=t;
                if(q[x][y]==q[y][x]) ++sum1;
                if(q[y][x]) ++sum2;
            }
            if(ch=='-')
            {
                cin>>x>>y;
                if(q[x][y]==q[y][x]) --sum1;
                if(q[y][x]) --sum2;
                q[x][y]=0;
            }
            if(ch=='?')
            {
                cin>>x;
                x&=1;
                if(x)
                {
                    if(sum2>0) cout<<"YES\n";
                    else cout<<"NO\n";
                }
                else
                {
                    if(sum1>0) cout<<"YES\n";
                    else cout<<"NO\n";
                }
            }
        }    

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
2 3 2 3 2
1 2 3 4
 a b c
4 3 2 1
 a b c

*/