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
    int n,m,sum;
    int a[N],c[N],b[N],p[N];
    int f[N];
    int st[N],top;
    inline int find(int k){return f[k]==k?k:f[k]=find(f[k]);}
    inline void check(int k)
    {
        //cout<<k<<"!!"<<endl;
        for(int j=k,i=n;j>=1;--i,--j) b[j]=i;
        for(int j=k+1,i=1;j<=n;++j,++i) b[j]=i;
        for(int i=1;i<=n;++i) {p[b[i]]=i;}
        for(int i=1;i<=n;++i) {f[i]=i;}
        for(int i=1;i<=n;++i)
        {
            int x=find(i),y=find(p[a[i]]);
            f[x]=y;
        }
        int sum=n;
        for(int i=1;i<=n;++i) if(f[i]==i) --sum;
        if(sum<=m) st[++top]=k;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        //for(int i=1;i<=n;++i) cout<<s[i];
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m;sum=0;
            for(int i=0;i<=n;++i) c[i]=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                int tmp=i-a[i];
                if(tmp<0) tmp+=n;
                c[tmp]++;
            }
            top=0;
            for(int i=0;i<n;++i) if(c[i]>=n-m*2)
                check(i);
            cout<<top<<' ';
            for(int i=1;i<=top;++i) cout<<st[i]<<' ';
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