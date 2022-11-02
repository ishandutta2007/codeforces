#include <bits/stdc++.h>
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
const unsigned mod=998244353;
const unsigned _mod=1e9+7;
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
int n,m,k,ans,a[100010];
vector<int> G[100010];
bool flag;
ll p[300010],cnt;
bool v[1000010];void prim_init(int n){v[1]=1;rep(i,2,n){if(!v[i])p[++cnt]=i;rep(j,1,cnt){if(p[j]*i>n)break;v[p[j]*i]=p[j];if(!(i%p[j]))break;}}}
int dfs(int u,int fa)
{
    if (!flag) return 0;
    int tot=G[u].size();
    rep_(i,0,G[u]) if (G[u][i]!=fa) tot-=dfs(G[u][i],u);
    if (tot%k&&(tot-1)%k) flag=0;
    if (!ans)
    {
        if (tot%k==0) return ans=tot,1;
        else return ans=tot-1,0;
    } 
    else 
    {
        if (tot%k==0) return ans=__gcd(ans,tot),1;
        else return ans=__gcd(ans,tot-1),0;
    }
}
int main()
{
    prim_init(1e5);
    DC
    {
        cin>>n;
        a[1]=ksm(2,n-1);
        rep(i,1,n-1) 
        {
            int x,y;
            rd(x),rd(y);
            G[x].push_back(y),G[y].push_back(x);
        }
        rep(i,2,n) if ((n-1)%i==0&&!v[i]) 
        {
            ans=0;
            k=i;
            flag=1;
            dfs(1,0);
            a[ans]|=flag;
        }
        F(i) if (i!=1) a[1]-=a[i];
        a[1]+=mod;
        a[1]%=mod;
        F(i) cout<<a[i]<<" \n"[i==n];
        F(i) a[i]=0;
        F(i) G[i].clear();
    }
    return 0;
}