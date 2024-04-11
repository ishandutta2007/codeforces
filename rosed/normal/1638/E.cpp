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
    int n,m;
    string opt;
    int sum[N];
    struct segment_tree
    {
        int tag1[N<<2],tag2[N<<2];
        int col[N<<2];
        inline void build(int l,int r,int p)
        {
            col[p]=1;
            if(l==r) return;
            build(l,mid,ls(p));
            build(mid+1,r,rs(p));
        }
        inline void tag_union(int p,int c,int k)
        {
            tag1[p]+=k;
            if(c)col[p]=c,tag2[p]=c;
        }
        inline void pushdown(int p)
        {
            tag_union(ls(p),tag2[p],tag1[p]);
            tag_union(rs(p),tag2[p],tag1[p]);
            tag1[p]=tag2[p]=0;
        }
        inline void update(int tl,int tr,int l,int r,int p,int c)
        {
            if(col[p]&&tl<=l&&r<=tr)
            {
                tag_union(p,c,sum[col[p]]-sum[c]);
                return;
            }
            if(tag1[p]||tag2[p]) pushdown(p);
            if(tl<=mid) update(tl,tr,l,mid,ls(p),c);
            if(tr>mid) update(tl,tr,mid+1,r,rs(p),c);
            if(col[ls(p)]==col[rs(p)]) col[p]=col[ls(p)];
            else col[p]=0;
        }
        inline int query(int pos,int l,int r,int p)
        {
            if(l==r) return tag1[p]+sum[col[p]];
            if(tag1[p]||tag2[p]) pushdown(p);
            if(pos<=mid) return query(pos,l,mid,ls(p));
            return query(pos,mid+1,r,rs(p));
        }
    }T;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        T.build(1,n,1);
        for(int i=1;i<=m;++i)
        {
            cin>>opt;
            if(opt[0]=='C')
            {
                int x,y,z;cin>>x>>y>>z;
                T.update(x,y,1,n,1,z);
            }
            if(opt[0]=='A')
            {
                int x,y;cin>>x>>y;
                sum[x]+=y;
            }
            if(opt[0]=='Q')
            {
                int x;cin>>x;
                cout<<T.query(x,1,n,1)<<'\n';
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