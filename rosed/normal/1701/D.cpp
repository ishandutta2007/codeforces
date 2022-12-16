#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,inf=2e9;
    int n,m;
    int a[N],b[N];;
    struct node
    {
        int l,r,id;
        inline bool operator < (const node &t) const
        {
            return r<t.r;
        }
    }q[N];
    int f[N];
    inline int find(int k)
    {
        return f[k]==k?k:f[k]=find(f[k]);
    }
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq; cin>>qwq;
        while(qwq--)
        {
            cin>>n;
            for(int i=1;i<=n;++i)
            {
                f[i]=i;
                cin>>b[i];
                int l=1,r=n;
                while(l<=r)
                {
                    if(i/mid<=b[i]) q[i].l=mid,r=mid-1;
                    else l=mid+1;
                }
                l=1,r=n;
                while(l<=r)
                {
                    if(i/mid>=b[i]) q[i].r=mid,l=mid+1;
                    else r=mid-1;
                }
                q[i].id=i;
                //cout<<q[i].l<<' '<<q[i].r<<"!!!"<<endl;
            }
            sort(q+1,q+n+1);
            for(int i=1;i<=n;++i)
            {
                int x=find(q[i].l);
                a[q[i].id]=x;
                f[find(x)]=find(x+1);
            }
            for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


1*2+3+4+5+6+7+8
*/