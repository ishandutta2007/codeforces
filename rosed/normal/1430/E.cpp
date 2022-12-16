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
    const int N=1e6+10,mod=1e9+7,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<vector<int> > pos(26);
        for(int i=0;i<n;++i)
        {
            pos[s[i]-'a'].emplace_back(i);
        }
        vector<int> tr(n+1);
        auto update=[&](int x,int k) -> void
        {
            for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=k;
        };
        auto query=[&](int x) -> int
        {
            int sum=0;
            for(int i=x;i>0;i-=lowbit(i)) sum+=tr[i];
            return sum;
        };
        int ans=0;
        reverse(s.begin(),s.end());
        for(int i=n-1;i>=0;--i)
        {
            int c=s[i]-'a';
            int p=pos[c].back();
            pos[c].pop_back();
            //cout<<c<<' '<<i<<' '<<p<<"!!"<<endl;
            ans+=i-(p-query(p));
            update(p+1,1);
            //cout<<ans<<"!!!"<<endl;
        }
        cout<<ans<<'\n';
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