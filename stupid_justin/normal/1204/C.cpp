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
const int N=105;
const int M=1e6+5;
const int SZ=550;
const double eps=1e-9;
const int mod=998244853;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m;
vector<int> v;
int dis[N][N];
string s;
int a[M],la;
signed main()
{
    rd(n);
    for (int i=1;i<=n;i++) 
    {
        cin>>s;s=" "+s;
        for (int j=1;j<=n;j++) if (i==j) dis[i][j]=0;else dis[i][j]=s[j]=='1'?1:1e9;
    }
    for (int k=1;k<=n;k++) for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    rd(m);
    for (int i=1;i<=m;i++) rd(a[i]);
    v.push_back(a[1]);la=1;
    for (int i=2;i<=m;i++) 
    {
        if (dis[v.back()][a[i]]!=i-la) v.push_back(a[i-1]),la=i-1;
    }
    v.push_back(a[m]);
    cout<<v.size()<<endl;
    for (int x:v) cout<<x<<" ";

}
/*
*/