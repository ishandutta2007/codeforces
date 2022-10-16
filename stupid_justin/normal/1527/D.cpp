#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=2e5+5;
const int M=6e6+6;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int n,ans,m,l,r,L,R;
int a[N],b[N],sz1[N],sz2[N],FA[N],S[N];
vector<int> T[N];
void dfs(int u,int fa,int sz[])
{
    FA[u]=fa;
    sz[u]=1;for (int v:T[u]) if (v!=fa) dfs(v,u,sz),sz[u]+=sz[v];
}
signed main()
{
    int qwq;rd(qwq);while (qwq--)
    {
        rd(n);
        for (int i=0;i<=n;i++) T[i].clear();
        for (int i=1,x,y;i<n;i++) rd(x),rd(y),T[x].push_back(y),T[y].push_back(x);
        for (int i=0;i<=n+1;i++) a[i]=0,sz1[i]=sz2[i]=0,S[i]=0;
        l=r=0;dfs(0,-1,sz1);a[0]=n*(n-1)/2;
        a[1]=2*n-2;for (int v:T[0]) a[1]+=(n-1-sz1[v])*sz1[v];a[1]/=2;
        dfs(1,-1,sz2);l=1;r=0;L=sz1[l];R=sz2[r];a[2]=L*R;
        int x=0;while (x!=1) S[x]=1,x=FA[x];S[1]=1;
        for (int k=2;k<n;k++)
        {
            if (S[k]) {a[k+1]=L*R;continue;}int x=k;
            while (!S[x]) x=FA[x];
            if (x==l) 
            {
                int x=k;while (x!=l) S[x]=1,x=FA[x];
                l=k,L=sz1[l],a[k+1]=L*R;
            } else if (x==r) 
            {
                int x=k;while (x!=r) S[x]=1,x=FA[x];
                r=k;R=sz2[r],a[k+1]=L*R;
            } else break;
        }
        for (int i=0;i<=n;i++) a[i]-=a[i+1],cout<<a[i]<<" ";
        puts("");

    }
}