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
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=1e18;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        struct pr
        {
            int l,r;
            mutable int v;
            bool operator < (const pr &t) const
            {
                return l<t.l;
            }
        };
        set<pr> q;


        q.insert((pr){1,inf+1,0});
        auto split=[&](int x) -> set<pr>::iterator
        {
            pr tmp;
            tmp.l=x,tmp.r=x,tmp.v=0;
            auto it=q.lower_bound(tmp);
            if(it!=q.end()&&(*it).l==x) return it;
            --it;
            int l=(*it).l,r=(*it).r,v=(*it).v;
            q.erase(it);
            q.insert((pr){l,x-1,v});
            q.insert((pr){x,r,v});
            return q.lower_bound((pr){x,r,v});
        };
        auto assign=[&](int l,int r,int v) -> void
        {
            auto t2=split(r+1),t1=split(l);
            q.erase(t1,t2);
            q.insert(pr{l,r,v});
        };
        auto rever=[&](int l,int r) -> void
        {
            auto t2=split(r+1),t1=split(l);
            for(set<pr>::iterator t=t1;t!=t2;++t)
            {
                (*t).v=1-(*t).v;
            }
        };
        for(int i=1;i<=n;++i)
        {
            int opt,l,r;
            cin>>opt>>l>>r;
            if(opt==1) assign(l,r,1);
            if(opt==2) assign(l,r,0);
            if(opt==3) rever(l,r);
            for(auto it=q.begin();it!=q.end();++it)
            {
                if(!(*it).v)
                {
                    cout<<(*it).l<<'\n';
                    break;
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

*/