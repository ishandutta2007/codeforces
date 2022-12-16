#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,inf=2e9,mod=998244353;
    int n;
    int a[N],b[N];
    int num[2],s[2][N];
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n;
            int tot=0,t=0;
            num[0]=num[1]=0;
            s[0][1]=s[1][1]=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                if(!a[i]) ++tot;
                else s[t][++num[t]]=a[i];
            }
            while(num[t]>1)
            {
                //for(int i=1;i<=num[t];++i) cout<<s[t][i]<<" \n"[i==num[t]];
                t^=1;
                num[t]=0;
                if(tot>0)
                {
                    s[t][++num[t]]=s[t^1][1];
                    --tot;
                }
                for(int j=1;j<num[t^1];++j)
                {
                    int x=s[t^1][j+1]-s[t^1][j];
                    if(!x) ++tot;
                    else s[t][++num[t]]=x;
                }
                sort(s[t]+1,s[t]+num[t]+1);
            }
            if(!num[t]) cout<<0<<'\n';
            else cout<<s[t][1]<<'\n';
            //cout<<ans<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


a a b

t=b-a;

3 4 5
3 3 4
2 3 3
2 2 2

2 4 4

*/