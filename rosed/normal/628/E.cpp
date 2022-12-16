#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3000+10,mod=998244353,inf=2e9;
    int n,m;
    long long ret;
    char s[N][N];
    int pre[N][N],suf[N][N];
    int xf[N][N];
    struct BIT
    {
        int tr[N];
        inline void update(int x)
        {
            for(int i=x;i<=n;i+=lowbit(i)) ++tr[i];
        }
        inline int query(int x)
        {
            int sum=0;
            for(int i=x;i>=1;i-=lowbit(i)) sum+=tr[i];
            return sum;
        }
        inline int query(int l,int r)
        {
            return query(r)-query(l-1);
        }
    }T[N*2];
    struct node
    {
        int id,k,l,r;
        inline bool operator < (const node &t) const
        {
            return k>t.k;
        }
    }a[N*N],b[N*N];
    int numa,numb;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            cin>>(s[i]+1);
            for(int j=1;j<=m;++j)
            {
                if(s[i][j]=='z') pre[i][j]=pre[i][j-1]+1;
            }
            for(int j=m;j>=1;--j)
            {
                if(s[i][j]=='z') suf[i][j]=suf[i][j+1]+1;
            }
        }
        for(int i=n;i>=1;--i)
        {
            for(int j=1;j<=m;++j)
            {
                if(s[i][j]=='z') xf[i][j]=xf[i+1][j-1]+1;
            }
        }
        for(int i=1;i<n+m;++i)
        {
            int t=i+1,k=1;
            for(int j=max(1,t-m);j<=n&&t-j>=1;++j,++k)
            {
                int x=j,y=t-j;
                if(s[x][y]=='.') continue;
                a[++numa]=(node){i,suf[x][y]-j,k,k};
                int tmp=min(i,n-max(1,t-m)+1);
                b[++numb]=(node){i,-x+1,k,min(k+min(pre[x][y],xf[x][y])-1,tmp)};
            }
        }
        sort(a+1,a+numa+1);
        sort(b+1,b+numb+1);
        int tl=1,tr=1;
        for(int i=1;i<=numa+numb;++i)
        {
            if(tl<=numa&&(tr>numb||a[tl].k>=b[tr].k))
            {
                T[a[tl].id].update(a[tl].l);
                ++tl;
            }
            else
            {
                //cout<<b[tr].id<<' '<<b[tr].l<<' '<<b[tr].r<<' '<<T[b[tr].id].query(b[tr].l,b[tr].r)<<"!!!"<<endl;
                ret+=T[b[tr].id].query(b[tr].l,b[tr].r);
                ++tr;
            }
        }
        cout<<ret<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
4 4
zzzz
z.z.
.zzz
zzzz

*/