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
    int n,pos1,pos2;
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            pos1=n,pos2=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                for(int j=1;j<i;++j)
                {
                    if(a[j]>a[i]&&(j<pos1||(j==pos1&&a[i]<a[pos2])))
                    {
                        pos1=j,pos2=i;
                    }
                }
            }
            if(pos2) reverse(a+pos1,a+pos2+1);
            for(int i=1;i<=n;++i) cout<<a[i]<<' ';
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