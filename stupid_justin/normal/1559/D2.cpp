#include<bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
const int SZ=550;
const double eps=1e-9;
const int mod=998244853;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m1,m2;
int fa1[N],fa2[N];
int getfa1(int x){if (fa1[x]==x) return x;return fa1[x]=getfa1(fa1[x]);}
int getfa2(int x){if (fa2[x]==x) return x;return fa2[x]=getfa2(fa2[x]);}
void merge1(int x,int y){x=getfa1(x);y=getfa1(y);if (x!=y) fa1[x]=y;}
void merge2(int x,int y){x=getfa2(x);y=getfa2(y);if (x!=y) fa2[x]=y;}
vector<pair<int,int> >ans;
vector<int> ans1,ans2;
signed main()
{
    rd(n);rd(m1);rd(m2);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rand(seed);
    for (int i=1;i<=n;i++) fa1[i]=fa2[i]=i;
    for (int i=1,u,v;i<=m1;i++) 
    {
        rd(u);rd(v);u=getfa1(u);v=getfa1(v);
        if (u!=v) fa1[u]=v;
    }
    for (int i=1,u,v;i<=m2;i++) 
    {
        rd(u);rd(v);u=getfa2(u);v=getfa2(v);
        if (u!=v) fa2[u]=v;
    }
    for (int i=2;i<=n;i++)
    {
        int u=getfa1(1),v=getfa1(i);
        int U=getfa2(1),V=getfa2(i);
        if (u!=v && U!=V) merge1(u,v),merge2(U,V),ans.push_back(make_pair(1,i));
    }
    for (int i=2;i<=n;i++) 
    {
        int u=getfa1(1),v=getfa1(i);
        if (u!=v) merge1(u,v),ans1.push_back(i);
    }
    for (int i=2;i<=n;i++) 
    {
        int u=getfa2(1),v=getfa2(i);
        if (u!=v) merge2(u,v),ans2.push_back(i);
    }
    cout<<ans.size()+min(ans1.size(),ans2.size())<<endl;
    for (pair<int,int> p:ans) cout<<p.first<<" "<<p.second<<"\n";
    for (int i=0;i<min(ans1.size(),ans2.size());i++) printf("%d %d\n",ans1[i],ans2[i]);
}
/*
*/