#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=2e9,mod=998244353;
    int n,m;
    int a[N];
    vector<int> col[N];
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n;
            for(int i=1;i<=n;++i) col[i].clear();
            for(int i=1;i<=n;++i)
            {
                int x;cin>>x;
                col[x].emplace_back(i);
            }
            for(int c=1;c<=n;++c)
            {
                int maxn=0,sum=0;
                int s=col[c].size();
                vector<int> q;
                for(int i=0;i<s;++i)
                {
                    if(i==0||(col[c][i]-col[c][i-1])%2==1) ++sum;
                    else
                    {
                        //maxn=max(maxn,sum);
                        //sum=1;
                        q.emplace_back(sum);
                        sum=1;
                    }
                }
                //maxn=max(maxn,sum);
                q.emplace_back(sum);
                s=q.size();
                for(int i=0;i<s;++i)
                {
                    maxn+=q[i];
                    if(i!=0) --maxn;
                }
                cout<<maxn<<' ';
            }
            cout<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


*/