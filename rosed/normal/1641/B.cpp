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
    int n;
    int a[N],b[N],nxt[N];
    int st[N],top,tot;
    map<int,int> q;
    struct node
    {
        int x,y;
    }ans[N];
    int cnt;
    inline void work(int l,int r)
    {
        int sum=0;
        for(int i=l+1;i<r;++i)
        {
            ans[++cnt]=(node){r+tot,a[i]};
            ++tot;++sum;
        }
        tot+=sum;
        st[++top]=(r-l)*2;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;top=tot=cnt=0;
            q.clear();
            for(int i=1;i<=n;++i)
            {
               cin>>a[i];
               ++q[a[i]];
            }
            bool flag=0;
            for(int i=1;i<=n;++i)
            {
                if(q[a[i]]%2==1)
                {
                    flag=1;break;
                }
            }
            if(flag) {cout<<"-1\n";continue;}
            for(int i=1;i<=n;++i) q[a[i]]=0;
                bool ok=0;
            for(int i=1;i<=n;++i)
            {
                bool flag=0;
                for(int j=i+1;j<=n;++j)
                {
                    if(a[i]==a[j])
                    {
                        work(i,j);
                        int t=j;
                        for(int k=i+1;k<j;++k) b[t--]=a[k];
                        for(int k=i+1;k<=j;++k) a[k]=b[k];
                        ++i;
                        flag=1;
                        break;
                    }
                }
                if(!flag) break;
                ok|=(i==n);
            }
            if(!ok) {cout<<"-1\n";continue;}
            cout<<cnt<<'\n';
            for(int i=1;i<=cnt;++i) cout<<ans[i].x<<' '<<ans[i].y<<'\n';
            cout<<top<<'\n';
            for(int i=1;i<=top;++i) cout<<st[i]<<" \n"[i==top];
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