#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=5e5+10,mod=998244353,inf=2e9;
    int n,m;
    int a[N],s[N],c[N],num;
    int dp[N];
    struct segment_tree
    {
        int ans[N<<2][3];
        inline void build(int l,int r,int p)
        {
            ans[p][0]=ans[p][1]=ans[p][2]=-inf;
            if(l==r) return;
            build(l,mid,ls(p));
            build(mid+1,r,rs(p));
        }
        inline void update(int pos,int l,int r,int p,int k,int id)
        {
            if(l==r)
            {
                ans[p][id]=max(ans[p][id],k);
                return;
            }
            if(pos<=mid) update(pos,l,mid,ls(p),k,id);
            if(pos>mid) update(pos,mid+1,r,rs(p),k,id);
            ans[p][id]=max(ans[ls(p)][id],ans[rs(p)][id]);
        }
        inline int query(int tl,int tr,int l,int r,int p,int id)
        {
            if(tl<=l&&r<=tr) return ans[p][id];
            int ret=-inf;
            if(tl<=mid) ret=max(ret,query(tl,tr,l,mid,ls(p),id));
            if(tr>mid) ret=max(ret,query(tl,tr,mid+1,r,rs(p),id));
            return ret;
        }
    }T;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int TT;cin>>TT;
        while(TT--)
        {
            cin>>n;
            num=0;
            c[++num]=0;
            for(int i=1;i<=n;++i)
            {
                dp[i]=-inf;
                cin>>a[i];
                s[i]=s[i-1]+a[i];
                c[++num]=s[i];
            }
            sort(c+1,c+num+1);
            num=unique(c+1,c+num+1)-c-1;
            T.build(1,num,1);
            int tmp=lower_bound(c+1,c+num+1,0)-c;
            T.update(tmp,1,num,1,0,0);
            T.update(tmp,1,num,1,0,1);
            T.update(tmp,1,num,1,0,2);
            for(int i=1;i<=n;++i)
            {
                int tmp=lower_bound(c+1,c+num+1,s[i])-c;
                if(tmp>1) dp[i]=max(dp[i],T.query(1,tmp-1,1,num,1,0)+i);
                dp[i]=max(dp[i],T.query(tmp,tmp,1,num,1,1));
                
                if(tmp<num) dp[i]=max(dp[i],T.query(tmp+1,num,1,num,1,2)-i);
                
                T.update(tmp,1,num,1,dp[i]-i,0);
                T.update(tmp,1,num,1,dp[i],1);
                T.update(tmp,1,num,1,dp[i]+i,2);
            }
            cout<<dp[n]<<'\n';
            //(j,s[j],dp[j])
            //dp[i]=dp[j]+(i-j)[s[i]-s[j]>0]
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
10
3
1 2 -3
4
0 -2 3 -4
5
-1 -2 3 -1 -1
6
-1 2 -3 4 -5 6
7
1 -1 -1 1 -1 -1 1
3
1 2 -3
4
0 -2 3 -4
5
-1 -2 3 -1 -1
6
-1 2 -3 4 -5 6
7
1 -1 -1 1 -1 -1 1

*/