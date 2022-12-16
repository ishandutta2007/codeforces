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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        vector<int> a(n+1);
        vector<vector<int> > ans(n+1);
        vector<int> d;
        int nn=n;
        for(int i=2;i<=nn;++i)
        {
            if(nn%i==0)
            {
                d.emplace_back(n/i);
                ans[n/i].resize(n/i);
                while(nn%i==0) nn/=i;
            }
        }
        sort(d.begin(),d.end());
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        int s=d.size();
        multiset<int> q;
        for(int i=0;i<s;++i)
        {
            int len=d[i];
            for(int st=0;st<len;++st)
            {
                int pos=st,sum=0;
                while(pos<n)
                {
                    sum+=a[pos];
                    pos+=len;
                }
                ans[len][st]=sum*len;
                q.insert(ans[len][st]);
            }
        }
        cout<<*(q.rbegin())<<'\n';
        for(int tt=1;tt<=m;++tt)
        {
            int x,y;cin>>x>>y;
            --x;
            for(int i=0;i<s;++i)
            {
                int len=d[i];
                int st=x%len;
                q.erase(q.find(ans[len][st]));
                ans[len][st]-=a[x]*len;
                ans[len][st]+=y*len;
                q.insert(ans[len][st]);
            }
            a[x]=y;
            cout<<*(q.rbegin())<<'\n';
        }
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