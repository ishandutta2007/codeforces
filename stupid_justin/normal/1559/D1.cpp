#include<bits/stdc++.h>
#define int long long
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
const int inf=0x3f3f3f3f3f3f3f;
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
signed main()
{
    rd(n);rd(m1);rd(m2);
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
    for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++)
    {
        if (getfa1(i)!=getfa1(j) && getfa2(i)!=getfa2(j))
        {
            ans.push_back(make_pair(i,j));
            merge1(i,j);merge2(i,j);
            
        }
    }
    cout<<ans.size()<<endl;
    for (pair<int,int> p:ans)
    {
        cout<<p.first<<" "<<p.second<<"\n";
    }
}
/*
*/