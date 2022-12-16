#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m;
    string s,t;
    string s1,t1;
    vector<int> a,b;
    inline void solve()
    {
        cin>>n;
        cin>>s>>t;
        a.clear(),b.clear();
        s1="",t1="";
        for(auto c:{'a','b','c'})
        {
            int sum=0;
            for(int i=0;i<n;++i)
            {
                if(s[i]==c) ++sum;
                if(t[i]==c) --sum;
            }
            if(sum!=0)
            {
                cout<<"NO\n";
                return;
            }
        }
        for(int i=0;i<n;++i)
        {
            if(s[i]!='b')
            {
                s1+=s[i];
                a.emplace_back(i);
            }
        }
        for(int i=0;i<n;++i)
        {
            if(t[i]!='b')
            {
                t1+=t[i];
                b.emplace_back(i);
            }
        }
        if(s1!=t1)
        {
            cout<<"NO\n";
            return;
        }
        m=a.size();
        for(int i=0;i<m;++i)
        {
            if(s1[i]=='a'?(a[i]>b[i]):(a[i]<b[i]))
            {
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;cin>>skx;
        while(skx--)
        {
            solve();
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
10
bcaabababc
cbbababaac

*/