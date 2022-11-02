#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define rep_(i,a,b) for(int i=(a);i<(b).size();++i)
#define F(a) rep(a,1,n)
#define M(a,b) memset(a,b,sizeof a)
#define DC int T;cin>>T;while(T--)
#define ll long long
#define Z(a,b) sort(a+1,a+b+1)
using namespace std;
const unsigned _mod=998244353;
const unsigned mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(auto &x){x=0;int f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y>0){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
#define int long long
int n,m,ans[100010],vis[100010],dis[100010],op,x,y;
set<int> S;
vector<int> G[100010];
int32_t main() 
{
    cin>>n>>m;
    M(ans,0x3f);
    S.insert(0);
    F(i) 
    {
        rd(op),rd(x),rd(y);
        rep(j,0,m) G[j].clear();
        queue<int> q;
        M(vis,0),M(dis,0x3f);
        for(auto x:S) vis[x]=1,dis[x]=0,q.push(x);
        int p=x/100000;
        if (x%100000) p++;
        int k;
        rep(j,0,m) 
        {
            if (op==1) k=p+j;
            if (op==2) 
            {
                k=x*j;
                int g=k/100000;
                if (k%100000) g++;
                k=g;
            }
            if (k<=m) G[j].push_back(k);
        }
        while(q.size()) 
        {
            int x=q.front(); 
            q.pop();
            for(auto y:G[x]) if (!vis[y]) vis[y]=1,dis[y]=dis[x]+1,q.push(y);
        }
        rep(j,0,m) if (dis[j]<=y&&vis[j]) ans[j]=min(ans[j],i);
        rep(j,0,m) if (vis[j]&&dis[j]<=y) S.insert(j);
    }
    rep(i,1,m) cout<<(ans[i]>n?-1:ans[i])<<' ';
    puts("");
    return 0;
}