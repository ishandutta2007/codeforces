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
    const int N=5e5+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,m;
    vector<int> a[N];
    int b[N];
    int s[N];
    int minn[N],maxn[N];
    int c[N],num;
    int sum[N];
    int t0;
    int idx,ans;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n>>m;
            num=0;
            for(int i=1;i<=m;++i) minn[i]=1e18,maxn[i]=0;
            for(int i=1;i<=n;++i)
            {
                s[i]=0;
                a[i].resize(m+1);
                for(int j=1;j<=m;++j)
                {
                    cin>>a[i][j];
                    minn[j]=min(minn[j],a[i][j]);
                    maxn[j]=max(maxn[j],a[i][j]);
                }
            }
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=m;++j) b[j]=a[i][j];
                sum[i]=0;
                for(int j=m;j>=1;--j)
                {
                    int tmp=max(0ll,b[j]-minn[j]);
                    if(!tmp) continue;
                    sum[i]+=tmp;
                    b[j-1]+=tmp;
                    b[j]-=tmp;
                }
                c[++num]=sum[i];
            }
            sort(c+1,c+num+1);
            for(int i=1;i<num;++i)
            {
                if(c[i]==c[i+1])
                {
                    t0=c[i];break;
                }
            }
            for(int i=1;i<=n;++i)
            {
                if(sum[i]!=t0)
                {
                    idx=i;
                    ans=sum[i]-t0;
                    break;
                }
            }
            cout<<idx<<' '<<ans<<'\n';
        }  
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
2
3 9
0 1 2 0 0 2 1 1 0
0 1 1 1 2 0 0 2 0
0 1 2 0 0 1 2 1 0
3 7
25 15 20 15 25 20 20
26 14 20 14 26 20 20
25 15 20 15 20 20 25

7
3 9
0 1 2 0 0 2 1 1 0
0 1 1 1 2 0 0 2 0
0 1 2 0 0 1 2 1 0
3 7
25 15 20 15 25 20 20
26 14 20 14 26 20 20
25 15 20 15 20 20 25
3 9
25 15 20 15 25 20 20 20 20
26 14 20 14 26 20 20 20 20
25 15 20 15 25 15 20 20 25
3 11
25 15 20 15 25 20 20 20 20 20 20
26 14 20 14 26 20 20 20 20 20 20
25 15 20 15 25 20 15 20 20 20 25
3 13
25 15 20 15 25 20 20 20 20 20 20 20 20
26 14 20 14 26 20 20 20 20 20 20 20 20
25 15 20 15 25 20 20 15 20 20 20 20 25
3 15
25 15 20 15 25 20 20 20 20 20 20 20 20 20 20
26 14 30 4 16 30 20 20 20 20 20 20 20 20 20
25 15 20 15 25 20 20 20 15 20 20 20 20 20 25
3 9
909459 479492 676924 224197 162866 164495 193268 742456 728277
948845 455424 731850 327890 304150 237351 251763 225845 798316
975446 401170 792914 272263 300770 242037 236619 334316 725899

*/