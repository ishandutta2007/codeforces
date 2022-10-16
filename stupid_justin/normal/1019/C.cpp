#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=1e6+5;
const int M=1e5+5;
const int mod=998244353;
int read(){int x=0;char ch=getchar();while(ch>'9'||ch<'0'){ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int n,m,k;
bool v[N];
vector<int> G[N];
signed main()
{
    rd(n);rd(m);for (int i=1,x,y;i<=m;i++) rd(x),rd(y),G[x].push_back(y);
    for (int i=1;i<=n;i++) if (!v[i]) for (int j:G[i]) if (j>i) v[j]=1;
    for (int i=n;i>=1;i--) if (!v[i]) for (int j:G[i]) if (j<i) v[j]=1;
    for (int i=1;i<=n;i++) if (!v[i]) k++;
    cout<<k<<endl;for (int i=1;i<=n;i++) if (!v[i]) cout<<i<<" ";cout<<endl;
    
}


/*
*/