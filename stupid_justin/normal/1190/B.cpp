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
int n,tot,sum;
int a[N];
signed main()
{
    rd(n);a[0]=-1;
    for (int i=1;i<=n;i++) rd(a[i]);
    sort(a+1,a+n+1);
    for (int i=1;i<n;i++) if (a[i]==a[i+1]) tot++;
    if (tot>=2) {puts("cslnb");return 0;}
    for (int i=1;i<n;i++) if (a[i]==a[i+1]) {if (a[i]-1==a[i-1]) {puts("cslnb");return 0;}}
    for (int i=1;i<=n;i++) sum+=a[i]-i+1;
    if (sum%2==0) puts("cslnb");else puts("sjfnb");
}
/*

*/