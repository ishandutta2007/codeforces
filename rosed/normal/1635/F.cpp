#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m;
    int a[N],w[N];
    int tl[N],tr[N],st[N],top;
    int ret[N];
    struct node
    {
        int l,r,id;
        inline bool operator < (const node &t) const
        {
            return r<t.r;
        }
    }q[N];
    vector<node> v[N];
    struct segment_tree
    {
        int ans[N<<2];
        inline void init()
        {
            memset(ans,0x3f,sizeof(ans));
        }
        inline void update(int pos,int l,int r,int p,int k)
        {
            ans[p]=min(ans[p],k);
            if(l==r) return;
            if(pos<=mid) update(pos,l,mid,ls(p),k);
            else update(pos,mid+1,r,rs(p),k);
        }
        inline int query(int tl,int tr,int l,int r,int p)
        {
            if(tl<=l&&r<=tr) return ans[p];
            int ret=2e18;
            if(tl<=mid) ret=min(ret,query(tl,tr,l,mid,ls(p)));
            if(tr>mid) ret=min(ret,query(tl,tr,mid+1,r,rs(p)));
            return ret;
        }
    }T;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qaq=1;
        while(qaq--)
        {
            cin>>n>>m;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i]>>w[i];
                while(top&&w[st[top]]>=w[i])
                {
                    tr[st[top--]]=i;
                }
                st[++top]=i;
            }
            while(top) tr[st[top--]]=n;
            for(int i=n;i;--i)
            {
                while(top&&w[st[top]]>=w[i])
                {
                    tl[st[top--]]=i;
                }
                st[++top]=i;
            }
            while(top) tl[st[top--]]=1;
            for(int i=1;i<=n;++i)
            {
                if(i-tl[i]>0) v[i].push_back((node){tl[i],(a[i]-a[tl[i]])*(w[i]+w[tl[i]])});
                if(tr[i]-i>0) v[tr[i]].push_back((node){i,(a[tr[i]]-a[i])*(w[i]+w[tr[i]])});
            }
            for(int i=1;i<=m;++i)
            {
                cin>>q[i].l>>q[i].r;
                q[i].id=i;
            }
            sort(q+1,q+m+1);
            T.init();
            int now=1;
            for(int i=1;i<=n;++i)
            {
                for(auto t:v[i])
                {
                    T.update(t.l,1,n,1,t.r);
                }
                while(now<=m&&q[now].r<=i)
                {
                    ret[q[now].id]=T.query(q[now].l,q[now].r,1,n,1);
                    ++now;
                }
            }
            for(int i=1;i<=m;++i) cout<<ret[i]<<'\n';
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