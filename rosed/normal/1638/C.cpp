#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=1e6+10,mod=1e9+7,inf=2e9;
    int n;
    int a[N];
    int st[N],top;
    int maxn[N],minn[N],col[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;top=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                col[i]=i;
                maxn[i]=minn[i]=a[i];
            }
            int sum=n;
            for(int i=n;i;--i)
            {
                while(top&&maxn[col[i]]>minn[col[st[top]]])
                {
                    maxn[col[st[top]]]=max(maxn[col[i]],maxn[col[st[top]]]);
                    minn[col[st[top]]]=min(minn[col[i]],minn[col[st[top]]]);
                    col[i]=col[st[top]];
                    --top;
                    --sum;
                }
                st[++top]=i;
            }
            cout<<sum<<'\n';
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