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
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    int n,k;
    char s[N];
    int a[N];
    // int f[N];
    // inline int find(int k){return f[k]==k?k:f[k]=find(f[k]);}
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>k;
            cin>>(s+1);
            for(int i=1;i<=n;++i)
            {
                a[i]=s[i]-'a';
                //f[i]=i;
            }
            // f[n+1]=n+1;
            // for(int i=1;i<=n;++i)
            // {
            //     if(a[i]==0) f[find(i)]=find(i+1);
            // }
            int r=0,tmp=0;
            while(r<n&&a[r+1]<=k) tmp=max(tmp,a[++r]);
            //cout<<r<<"!!!\n";
            k-=tmp;
            for(int i=1;i<=n;++i)
            {
                if(a[i]<=tmp) a[i]=0;
            }
            if(r<n)
            {
                ++r;
                for(int i=r+1;i<=n;++i)
                {
                    if(a[i]<=a[r]) a[i]=min(a[i],a[r]-k);
                    a[i]=max(a[i],0ll);
                }
                a[r]-=k;
            }
            for(int i=1;i<=n;++i) cout<<(char)(a[i]+'a');
            cout<<'\n';
            //for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
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