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
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        vector<array<int,2> > son(n*30);
        vector<int> sum(n*30);
        int rt=0;
        int tot=0;
        function<void(int,int,int&)> insert=[&](int k,int x,int &p) -> void
        {
            if(!p) p=++tot;
            ++sum[p];
            if(k<0) return;
            insert(k-1,x,son[p][(x>>k)&1]);
        };
        function<void(int,int,int&)> del=[&](int k,int x,int &p) -> void
        {
            --sum[p];
            if(k<0) return;
            del(k-1,x,son[p][(x>>k)&1]);
        };
        function<int(int,int,int,int&)> query=[&](int k,int x,int y,int &p) -> int
        {
            if(k<0) return 0;
            int b1=(x>>k)&1,b2=(y>>k)&1;
            if(!b2) return query(k-1,x,y,son[p][b1]);
            return query(k-1,x,y,son[p][b1^1])+sum[son[p][b1]];
        };
        for(int i=1;i<=n;++i)
        {
            int opt;cin>>opt;
            if(opt==1)
            {
                int x;cin>>x;
                insert(29,x,rt);
            }
            if(opt==2)
            {
                int x;cin>>x;
                del(29,x,rt);
            }
            if(opt==3)
            {
                int x,y;cin>>x>>y;
                cout<<query(29,x,y,rt)<<'\n';
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

*/