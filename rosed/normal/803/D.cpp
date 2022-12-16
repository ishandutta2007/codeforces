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
#define y1 uuuu
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        string s;
        int l=1,r=inf;
        vector<string> txt;
        vector<vector<int> > q;
        int m=0;
        while(cin>>s)
        {
            txt.emplace_back(s);
            vector<int> tmp;
            q.emplace_back(tmp);
            int len=s.length();
            int pre=-1;
            for(int i=0;i<len;++i)
            {
                if(s[i]=='-')
                {
                    q[m].emplace_back(i-pre-1);
                    pre=i;
                }
            }
            if(s[len-1]!='-')
            {
                q[m].emplace_back(len-1-pre);
            }
            ++m;
        }
        int &ret=q[m-1].back();
        --ret;
        int sum=0;
        for(int i=0;i<m;++i)
        {
            for(int c:q[i]){ l=max(l,c+1);}
        }
        auto check=[&](int x) -> bool
        {
            int t=1,s=0;
            for(int i=0;i<m;++i)
            {
                if(t>n) return 0;
                for(int c:q[i])
                {
                    if(s+c+1<=x) s+=c+1;
                    else
                    {
                        ++t;
                        s=c+1;
                    }
                }
                if(t>n) return 0;
            }
            return 1;
        };
        while(l<=r)
        {
            if(check(mid)) r=mid-1;
            else l=mid+1;
        }
        cout<<r+1<<'\n';
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