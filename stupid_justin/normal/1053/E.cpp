
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
const int N=2e6+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m,p=1;
int a[N],pre[N],suf[N],vis[N],nxt[N];
void del(int l,int r){suf[pre[l]]=suf[r];pre[suf[r]]=pre[l];}
int get(){while (vis[p]) p++;if (p>n) {puts("no");exit(0);}vis[p]=-1;return p;}
void solve(int l,int r)
{
	if ((r-l)&1) {puts("no");exit(0);}
	for (int i=l;i<=r;i=suf[i]) while (nxt[i])
    {
		if (nxt[i]>r) {puts("no");exit(0);}
		solve(suf[i],pre[nxt[i]]);
		del(suf[i],nxt[i]);
		nxt[i]=nxt[nxt[i]];
	}
	int sum=0,cnt=0,rt=a[pre[l]];
	for (int i=l;i<=r;i=suf[i]) sum++,cnt+=a[i]>0;
	sum=(sum+1)/2;
	if (cnt>sum) {puts("no");exit(0);};
	for (int i=suf[l];i<=r;i=suf[i]) if (!a[i] && cnt<sum) a[i]=get(),cnt++;
	if (sum==1 && cnt==0) a[l]=get();
	for (int i=l;suf[i]<=r;i=suf[i])
    {
		while (i>l && suf[i]<=r && a[pre[i]]==0 && a[i]!=0 && a[suf[i]]!=0) a[pre[i]]=a[suf[i]],del(i,suf[i]),i=pre[pre[i]];
		while (i>=l && suf[suf[i]]<=r && a[i]!=0 && a[suf[i]]!=0 && a[suf[suf[i]]]==0) a[suf[suf[i]]]=a[i],del(suf[i],suf[suf[i]]),i=pre[i];
	}
	for (int i=l;i<=r;i=suf[i]) if (!a[i]) a[i]=rt;
}
signed main()
{
    rd(n);m=2*n-1;for (int i=1;i<=m;i++) rd(a[i]);
	if (a[1]!=0 && a[m]!=0 && a[1]!=a[m]) {puts("no");exit(0);}
	a[1]=a[m]=a[1]|a[m];
	for (int i=0;i<=m;i++) pre[i]=i-1,suf[i]=i+1;
	for (int i=m;i;i--) if (a[i]) nxt[i]=vis[a[i]],vis[a[i]]=i;
	solve(1,m);puts("yes");for (int i=1;i<=m;i++) cout<<a[i]<<" ";cout<<endl;
}