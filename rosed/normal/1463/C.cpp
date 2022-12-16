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
        int n;cin>>n;
        int tl,tr,st,ed;
        tl=tr=st=ed=0;
        int sum=0;
        vector<int> t(n+2),p(n+2);
        for(int i=1;i<=n;++i) cin>>t[i]>>p[i];
            t[n+1]=inf;
        for(int i=1;i<=n;++i)
        {
            int tim,pos;
            tim=t[i],pos=p[i];
            if(tim>=tr)
            {
                tl=tim;
                st=ed;
                ed=pos;
                tr=tim+abs(st-ed);
                if(tr<=t[i+1]) ++sum;
            }
            else
            {
                int k=1;
                if(st>ed) k=-1;
                int tpos=st+k*(tim-tl);
                int tt=abs(pos-tpos);
                //cout<<i<<' '<<tpos<<' '<<ed<<' '<<pos<<' '<<tim<<' '<<lst<<"!!!!!!"<<endl;
                if(min(tpos,ed)<=pos&&pos<=max(tpos,ed)&&t[i]+tt<=t[i+1]) ++sum;
            }
            //cout<<i<<' '<<sum<<"!!"<<endl;
        }
        cout<<sum<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/