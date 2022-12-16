#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,maxn=2e5+50,inf=2e9,mod=998244353;
    int n,m,ret;
    int a[N];
    struct seg
    {
        int ans[N<<2],tag[N<<2];
        inline void pushdown(int l,int r,int p)
        {
            ans[ls(p)]=tag[p]*(mid-l+1);
            ans[rs(p)]=tag[p]*(r-mid);
            tag[ls(p)]=tag[rs(p)]=tag[p];
            tag[p]=-1;
        }
        inline void update(int tl,int tr,int l,int r,int p,int k)
        {
            if(tl>tr) return;
            if(tl<=l&&r<=tr)
            {
                ans[p]=(r-l+1)*k;
                tag[p]=k;
               // cout<<l<<' '<<r<<' '<<k<<"!!!!!!!!!!!!"<<endl;
                return;
            }
            if(tag[p]!=-1) pushdown(l,r,p);
            if(tl<=mid) update(tl,tr,l,mid,ls(p),k);
            if(tr>mid) update(tl,tr,mid+1,r,rs(p),k);
            ans[p]=ans[ls(p)]+ans[rs(p)];
        }
        inline int query(int tl,int tr,int l,int r,int p)
        {
            if(tl>tr) return 0;
            if(tl<=l&&r<=tr) return ans[p];
            if(~tag[p]) pushdown(l,r,p);
            int sum=0;
            if(tl<=mid) sum+=query(tl,tr,l,mid,ls(p));
            if(tr>mid) sum+=query(tl,tr,mid+1,r,rs(p));
            return sum;
        }
        inline int query2(int l,int r,int p)
        {
            if(l==r) return l;
            if(~tag[p]) pushdown(l,r,p);
            if(ans[rs(p)]>0) return query2(mid+1,r,rs(p));
            return query2(l,mid,ls(p));
        }
    }T;
    inline int find0(int pos)
    {
        int l=pos,r=maxn;
        while(l<=r)
        {
            if(T.query(pos,mid,1,maxn,1)==0) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
    inline int find1(int pos)
    {
        int l=pos,r=maxn;
        while(l<=r)
        {
            if(T.query(pos,mid,1,maxn,1)==mid-pos+1) l=mid+1;
            else r=mid-1;
        }
        return l;
    }

    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq=1;
        while(qwq--)
        {
            cin>>n>>m;
            memset(T.tag,-1,sizeof(T.tag));
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                int pos=find1(a[i]);
                T.update(pos,pos,1,maxn,1,1);
                if(pos-1>=a[i]) T.update(a[i],pos-1,1,maxn,1,0);
                //cout<<pos<<' '<<T.query(2,2,1,maxn,1)<<"!!!!!!!!!!!"<<endl;
            }
            
            for(int i=1;i<=m;++i)
            {
                int x,y;cin>>x>>y;
                int pos=find0(a[x]);
                T.update(pos,pos,1,maxn,1,0);
                if(pos-1>=a[x]) T.update(a[x],pos-1,1,maxn,1,1);
                a[x]=y;
                pos=find1(a[x]);
                T.update(pos,pos,1,maxn,1,1);
                if(pos-1>=a[x]) T.update(a[x],pos-1,1,maxn,1,0);
                cout<<T.query2(1,maxn,1)<<'\n';
                //cout<<T.query(2,2,1,maxn,1)<<"!!!!!!!!!!!!!"<<endl;
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

pre[i]=pre[i-1]/2+c[i]

*/