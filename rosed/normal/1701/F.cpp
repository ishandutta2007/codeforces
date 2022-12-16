#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=2e5+10,inf=2e9,maxn=2e5;
    int n,m;
    int a[N],ret;
    bool vis[N];
    struct matrix
    {
        int n,m;
        int g[4][4];
        matrix(){memset(g,0,sizeof(g));n=m=0;}
        inline matrix operator * (const matrix &t) const
        {
            matrix ret;
            ret.n=n,ret.m=t.m;
            // for(int i=1;i<=n;++i)
            //     for(int j=1;j<=m;++j) cout<<g[i][j]<<" \n"[j==m];
            //     cout<<endl;
            // for(int i=1;i<=t.n;++i)
            //     for(int j=1;j<=t.m;++j) cout<<t.g[i][j]<<" \n"[j==m];
            //     cout<<"-----------"<<endl;
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=t.m;++j)
                {
                    for(int k=1;k<=m;++k)
                    {
                        ret.g[i][j]+=g[i][k]*t.g[k][j];
                    }
                }
            }
            // for(int i=1;i<=ret.n;++i)
            //     for(int j=1;j<=ret.m;++j) cout<<ret.g[i][j]<<" \n"[j==m];
            //     cout<<"----------------------------------------"<<endl;
            return ret;
        }
    }e,tran,inv;
    struct seg
    {
        int sum[N<<2],tag[N<<2];
        matrix ans[N<<2],tag2[N<<2];
        inline void pushup(int p)
        {
            sum[p]=sum[ls(p)]+sum[rs(p)];
            for(int i=1;i<=3;++i) ans[p].g[1][i]=ans[ls(p)].g[1][i]+ans[rs(p)].g[1][i];
            ans[p].n=max(ans[ls(p)].n,ans[rs(p)].n);
            ans[p].m=max(ans[ls(p)].m,ans[rs(p)].m);
            //if(p==1) cout<<ans[p].g[1][1]<<"!!!!!!!!!!!!"<<endl;
        }
        inline void build(int l,int r,int p)
        {
            tag2[p]=e;
            if(l==r) return;
            // {
            //     ans[p].n=1,ans[p].m=3;
            //     ans[p].g[1][2]=ans[p].g[1][3]=1;
            // }
            build(l,mid,ls(p));
            build(mid+1,r,rs(p));
            pushup(p);
        }
        inline void pushdown(int l,int r,int p)
        {
            sum[ls(p)]+=tag[p]*(mid-l+1);
            sum[rs(p)]+=tag[p]*(r-mid);
            tag[ls(p)]+=tag[p];
            tag[rs(p)]+=tag[p];
            ans[ls(p)]=ans[ls(p)]*tag2[p];
            ans[rs(p)]=ans[rs(p)]*tag2[p];
            tag2[ls(p)]=tag2[ls(p)]*tag2[p];
            tag2[rs(p)]=tag2[rs(p)]*tag2[p];
            tag[p]=0;
            tag2[p]=e;
        }
        inline void update1(int tl,int tr,int l,int r,int p,int k)
        {
             //cout<<l<<' '<<r<<' '<<ans[p].g[1][1]<<' '<<ans[ls(p)].g[1][1]<<' '<<ans[rs(p)].g[1][1]<<"!!"<<endl;
            // matrix ret=ans[ls(p)]*tag2[p];
            // for(int i=1;i<=1;++i)
            //     for(int j=1;j<=3;++j) cout<<ans[ls(p)].g[i][j]<<" \n"[j==3];
            //cout<<"-------------\n";
            if(tl<=l&&r<=tr)
            {
                sum[p]+=(r-l+1)*k;
                tag[p]+=k;
                return;
            }
            pushdown(l,r,p);
            if(tl<=mid) update1(tl,tr,l,mid,ls(p),k);
            if(tr>mid) update1(tl,tr,mid+1,r,rs(p),k);
            pushup(p);
            //cout<<l<<' '<<r<<' '<<ans[p].g[1][1]<<' '<<ans[ls(p)].g[1][1]<<' '<<ans[rs(p)].g[1][1]<<"!!"<<endl;
        }
        inline void update2(int tl,int tr,int l,int r,int p,matrix k)
        {
            if(tl<=l&&r<=tr)
            {
                ans[p]=ans[p]*k;
                tag2[p]=tag2[p]*k;
                return;
            }
            pushdown(l,r,p);
            if(tl<=mid) update2(tl,tr,l,mid,ls(p),k);
            if(tr>mid) update2(tl,tr,mid+1,r,rs(p),k);
            pushup(p);
        }
        inline void update(int pos,int l,int r,int p,matrix k)
        {
            //cout<<l<<' '<<r<<' '<<ans[p].g[1][1]<<' '<<ans[ls(p)].g[1][1]<<' '<<ans[rs(p)].g[1][1]<<"!!"<<endl;
            if(l==r)
            {
                ans[p]=k;
                return;
            }
            pushdown(l,r,p);
            if(pos<=mid) update(pos,l,mid,ls(p),k);
            else update(pos,mid+1,r,rs(p),k);
            pushup(p);
            //cout<<l<<' '<<r<<' '<<ans[p].g[1][1]<<' '<<ans[ls(p)].g[1][1]<<' '<<ans[rs(p)].g[1][1]<<"!!"<<endl;
        }
        inline int query1(int tl,int tr,int l,int r,int p)
        {
            if(tl<=l&&r<=tr) return sum[p];
            pushdown(l,r,p);
            int tot=0;
            if(tl<=mid) tot+=query1(tl,tr,l,mid,ls(p));
            if(tr>mid) tot+=query1(tl,tr,mid+1,r,rs(p));
            return tot;
        }
    }T;
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        cin>>n>>m;
        e.n=3,e.m=3;
        for(int i=1;i<=3;++i) e.g[i][i]=1;
        tran=e;
        tran.g[2][1]=tran.g[3][2]=1;
        inv=tran;
        inv.g[2][1]=inv.g[3][2]=-1;
        inv.g[3][1]=1;
        T.build(1,maxn,1);
        for(int i=1;i<=n;++i)
        {
            int x;cin>>x;
            if(!vis[x])
            {
                //cout<<T.ans[1].g[1][1]<<"!!"<<endl;
                int l=max(1ll,x-m),r=x-1;
                if(x>1)
                {
                    T.update1(l,r,1,maxn,1,1);
                    T.update2(l,r,1,maxn,1,tran);
                }
                //cout<<T.ans[1].g[1][1]<<"----------"<<endl;
                int sum=T.query1(x,x,1,maxn,1);
                //cout<<sum<<"!!!!!!!!!!"<<endl;
                matrix tmp;
                tmp.n=1,tmp.m=3;
                tmp.g[1][1]=sum*(sum-1)/2,tmp.g[1][2]=sum,tmp.g[1][3]=1;
                //cout<<tmp.g[1][1]<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;
                //cout<<x<<"-------------"<<endl;
                T.update(x,1,maxn,1,tmp);
            }
            else
            {
                int l=max(1ll,x-m),r=x-1;
                if(x>1)
                {
                    T.update1(l,r,1,maxn,1,-1);
                    T.update2(l,r,1,maxn,1,inv);
                }
                matrix tmp;
                tmp.n=tmp.m=0;
                tmp.g[1][1]=tmp.g[1][2]=tmp.g[1][3]=0;
                T.update(x,1,maxn,1,tmp);
            }
            vis[x]^=1;
            cout<<T.ans[1].g[1][1]<<'\n';
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