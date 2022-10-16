
#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=30;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,q;
int c[N],a[N];
int query(int x,int k)
{
	if (k<0) return 0;
	int ans=0,tot=0;
	for (int i=x+1;i<n && (1<<(i-x))<=k;i++){int t=min(k>>(i-x),a[i]);k-=t<<(i-x);a[i]-=t;a[x]+=t<<(i-x);if (t) ans+=t*((1<<(i-x))-1);}
	if (!k) return ans;
	for (int i=0;i<=x;i++) tot+=a[i]*((1<<i)-1);
	if (tot>=k) return ans+k;
	for (int i=x+1;i<n;i++) if (a[i]) {a[i-1]+=2,a[i]--,ans++;if (i==x+1) k-=2;return ans+query(x,k);}
	return -1;
}
signed main()
{
    rd(n);rd(q);for (int i=0;i<n;i++) rd(c[i]);
    while (q--){int op,x,k;rd(op);rd(x);rd(k);if (op==1) c[x]=k;else {memcpy(a,c,sizeof(c));for (int i=0;i<=x;i++) k-=a[i];cout<<query(x,k)<<endl;}}
    
}