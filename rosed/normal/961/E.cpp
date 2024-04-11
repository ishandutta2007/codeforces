#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,mod=998244353,inf=2e9;
    int n,m,ans;
    int a[N];
    struct BIT
    {
        int tr[N];
        inline void update(int x,int k)
        {
           for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=k;
        }
        inline int query(int x)
        {
           int sum=0;
           for(int i=x;i;i-=lowbit(i)) sum+=tr[i];
           return sum;
        }
    }T;
    typedef pair<int,int> p;
    priority_queue<p> q;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        for(int i=n;i>=1;--i)
        {

            
            while(!q.empty()&&q.top().first>=i)
            {
                p now=q.top();q.pop();
                T.update(now.second,1);
            }
            int tmp=min(n,a[i]);
            ans+=T.query(tmp);
            q.push(p(a[i],i));
        }
        cout<<ans<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
4 4
zzzz
z.z.
.zzz
zzzz

*/