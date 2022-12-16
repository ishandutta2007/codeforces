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
    int n,m,qq;
    int a[N];
    int stx,sty,edx,edy,k;
    struct seg
    {
        int ans[N<<2];
        inline void build(int l,int r,int p)
        {
            if(l==r)
            {
                ans[p]=a[l];
                return;
            }
            build(l,mid,ls(p));
            build(mid+1,r,rs(p));
            ans[p]=max(ans[ls(p)],ans[rs(p)]);
        }
        inline int query(int tl,int tr,int l,int r,int p)
        {
            if(tl<=l&&r<=tr) return ans[p];
            int ret=0;
            if(tl<=mid) ret=max(ret,query(tl,tr,l,mid,ls(p)));
            if(tr>mid) ret=max(ret,query(tl,tr,mid+1,r,rs(p)));
            return ret;
        } 
    }T;
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq=1;
        while(qwq--)
        {
            cin>>n>>m;
            for(int i=1;i<=m;++i)
            {
                cin>>a[i];
            }
            T.build(1,m,1);
            cin>>qq;
            for(int i=1;i<=qq;++i)
            {
                cin>>stx>>sty>>edx>>edy>>k;
                if(sty>edy) swap(stx,edx),swap(sty,edy);
                int maxn=T.query(sty,edy,1,m,1)+1;
                maxn=max(maxn,max(stx,edx));
                int tmp=(maxn-stx)%k;
                maxn+=(k-tmp)%k;
                if((edy-sty)%k!=0||(maxn-stx)%k!=0||(maxn-edx)%k!=0||maxn>n) cout<<"NO\n";
                else cout<<"YES\n";
            }
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