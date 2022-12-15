#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=1e9+7,inf=1e18;
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    //k1
    vector<string> a(n+1);
    vector<int> num(n+1);
    vector<int> pc(1<<15);
    for(int i=1;i<(1<<15);++i) pc[i]=pc[i>>1]+(i&1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        for(int k=0;k<m;++k)
        {
            if(a[i][k]=='1') num[i]|=(1ll<<k);
        }
    }
    int ans=0,ret=0;
    auto fwt=[&](vector<int> &a,int n) -> void
    {
        for(int k=0;(1<<k)<n;++k)
        {
            for(int s=0;s<n;++s)
            {
                if(((s>>k)&1)==0) a[s]+=a[s^(1<<k)];
            }
        }
    };
    vector<bool> vis(n+1);
    for(int t=0;t<80;++t)
    {
        int i=rand()*rand()%n+1;
        while(n>1000&&vis[i])
        {
            i=rand()%n+1;
        }
        vis[i]=1;
        vector<int> bit;
        vector<int> id(m,-1);
        int idx=0;
        for(int k=0;k<m;++k)
        {
            if(a[i][k]=='1')
            {
                bit.emplace_back(k);
                id[k]=idx++;
            }
        }
        vector<int> f(1<<idx,0);
        for(int i=1;i<=n;++i)
        {
            int tmp=0;
            for(int k:bit)
            {
                if((num[i]>>k)&1)
                {
                    tmp|=(1<<id[k]);
                }
            }
            ++f[tmp];
        }
        fwt(f,1<<idx);
        for(int s=0;s<(1<<idx);++s)
        {
            if(f[s]<(n+1)/2) continue;
            int sum=pc[s];
            if(sum>ans)
            {
                ans=sum;
                ret=0;
                for(int k=0;k<idx;++k) if((s>>k)&1)
                {
                    ret|=(1ll<<bit[k]);
                }
            }
        }
    }
    for(int k=0;k<m;++k)
    {
        cout<<((ret>>k)&1);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    srand(time(0));
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}
/*
5+8+8+8
ababca+ccac+ba+ba
*/