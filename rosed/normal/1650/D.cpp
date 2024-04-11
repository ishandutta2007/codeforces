#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=2e9,mod=1e9+7;
    int n,m;
    int a[N],b[N],c[N];
    int pos[N];
    int st[N],top;
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
                pos[a[i]]=i;
            }
            for(int i=n;i;--i)
            {
                int tmp=pos[i];
                st[++top]=tmp%i;
                for(int j=tmp;j;--j)
                {
                    b[i-(tmp-j)]=a[j];
                    //cout<<i-(tmp-j)<<"!!!!"<<endl;
                }
                for(int j=i;j>tmp;--j)
                {
                    b[i-tmp-(i-j)]=a[j];
                }
                for(int j=1;j<=i;++j) a[j]=b[j];
                for(int j=1;j<=n;++j) pos[a[j]]=j;
                //for(int j=1;j<=n;++j) cout<<b[j]<<' ';
                //    cout<<endl;
            }
            while(top) cout<<st[top--]<<' ';
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
5 5
5 1 2
6 2 3
4 3 5
6 2 4
5 1 3

*/