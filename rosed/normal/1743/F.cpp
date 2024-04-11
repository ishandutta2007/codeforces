#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
const int mod=998244353;
void solve()
{
    auto fast=[&](int x,int k) -> int
    {
        int ret=1;
        while(k)
        {
            if(k&1) ret=ret*x%mod;
            x=x*x%mod;
            k>>=1;
        }
        return ret;
    };
    int n;
    cin>>n;
    typedef array<int,2> pr;
    typedef array<pr,2> matrix;
    vector<pr> a(n+1);
    vector<int> c(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i][0]>>a[i][1];
        ++a[i][0];
        ++a[i][1];
    }
    int m=3e5+1;
    vector<pr> ans(4*m+5);
    vector<matrix> tag(4*m+5);
    function<void(int,int,int)> build=[&](int l,int r,int p) -> void
    {
        tag[p][0][0]=tag[p][1][1]=1;
        tag[p][0][1]=tag[p][1][0]=0;
        if(l==r)
        {
            if(a[1][0]<=l&&l<=a[1][1]) ans[p][1]=1;
            else ans[p][0]=1;
            return;
        }
        build(l,mid,ls(p));
        build(mid+1,r,rs(p));
        ans[p][0]=(ans[ls(p)][0]+ans[rs(p)][0])%mod;
        ans[p][1]=(ans[ls(p)][1]+ans[rs(p)][1])%mod;
    };
    build(1,m,1);
    auto work=[&](int l,int r,int p,matrix tmp) -> void
    {
        ans[p]={ans[p][0]*tmp[0][0]+ans[p][1]*tmp[1][0],ans[p][0]*tmp[0][1]+ans[p][1]*tmp[1][1]};
        ans[p][0]%=mod;
        ans[p][1]%=mod;
        matrix ret;
        ret[0][0]=ret[0][1]=ret[1][0]=ret[1][1]=0;
        for(int i=0;i<2;++i)
        {
            for(int j=0;j<2;++j)
            {
                for(int k=0;k<2;++k)
                {
                    ret[i][j]+=tag[p][i][k]*tmp[k][j];
                    ret[i][j]%=mod;
                }
            }
        }
        tag[p]=ret;
    }; 
    auto pushdown=[&](int l,int r,int p)
    {
        work(l,mid,ls(p),tag[p]);
        work(mid+1,r,rs(p),tag[p]);
        tag[p][0][0]=tag[p][1][1]=1;
        tag[p][0][1]=tag[p][1][0]=0;
    };
    function<void(int,int,int,int,int,matrix)> update=[&](int tl,int tr,int l,int r,int p,matrix k) -> void
    {
        if(tl<=l&&r<=tr)
        {
            work(l,r,p,k);
            return;
        }
        pushdown(l,r,p);
        if(tl<=mid) update(tl,tr,l,mid,ls(p),k);
        if(tr>mid) update(tl,tr,mid+1,r,rs(p),k);
        ans[p][0]=(ans[ls(p)][0]+ans[rs(p)][0])%mod;
        ans[p][1]=(ans[ls(p)][1]+ans[rs(p)][1])%mod;
    };
    // cout<<ans[1][1]<<' '<<ans[1][0]<<'\n';
    for(int i=2;i<=n;++i)
    {
        matrix tmp;
        tmp[0][0]=tmp[1][1]=tmp[0][1]=tmp[1][0]=0;
        tmp[1][1]++;tmp[0][1]++;//1
        tmp[0][0]++;tmp[1][1]++;//1
        tmp[0][1]++;tmp[1][0]++;//1
        update(a[i][0],a[i][1],1,m,1,tmp);


        tmp[0][0]=tmp[1][1]=tmp[0][1]=tmp[1][0]=0;
        tmp[0][0]++;tmp[1][1]++;//0
        tmp[0][0]++;tmp[1][0]++;//0
        tmp[0][0]++;tmp[1][1]++;//0
        if(1<=a[i][0]-1) update(1,a[i][0]-1,1,m,1,tmp);
        if(a[i][1]+1<=m) update(a[i][1]+1,m,1,m,1,tmp);
        // cout<<ans[1][1]<<'\n';
    }
    cout<<ans[1][1]<<'\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // red::__init();
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}
/*
[3,5] [4,8] 
[3,8] 6
[4,5] 2
[3,3],[6,8] 4
*/