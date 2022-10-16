#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define endl "\n"
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define y1 _
#define pii pair<int,int> 
#define mp make_pair
using namespace std;
const int N=1e6+5;
const int M=12505;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

vector<int> G[M],ID[M];
int S[M],id[M];
int u[N],v[N],w[M],sum[M],h[N];
int W[N];
int n,m;
signed main()
{
    rd(n);rd(m);
    for (int i=1;i<=m;i++) rd(u[i]),rd(v[i]);
    for (int i=1;i<=m;i++) G[u[i]].emplace_back(v[i]),G[v[i]].emplace_back(u[i]),ID[u[i]].emplace_back(i),ID[v[i]].emplace_back(i);
    for (int i=1;i<=m;i++) W[i]=1,sum[u[i]]++,sum[v[i]]++;
    for (int i=1;i<=n;i++)
    {
        int sz=0;
        for (int j=0;j<G[i].size();j++) if (G[i][j]<i) S[sz]=G[i][j],id[sz]=ID[i][j],sz++;
        for (int j=0;j<sz;j++) if (w[S[j]]==0) w[S[j]]++,W[id[j]]--,sum[i]--;
        for (int j=0;j<sz;j++) h[sum[S[j]]]=1;
        int k=0;
        while (h[sum[i]]) {w[S[k]]--;W[id[k]]++;sum[i]++;k++;}
        for (int j=0;j<sz;j++) h[sum[S[j]]]=0;
    }

    int tot=0;
    for (int i=1;i<=n;i++) if (w[i]) tot++;
    cout<<tot<<endl;
    for (int i=1;i<=n;i++) if (w[i]) cout<<i<<" ";cout<<endl;
    for (int i=1;i<=m;i++) cout<<u[i]<<" "<<v[i]<<" "<<W[i]<<endl;
}
/*

*/