#include<bits/stdc++.h>
#define int long long
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=2e5+5;
const int M=21;
const int maxn=5e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,m,k,p,ans,l,r;
int a[N],h[N];
struct Node
{
	int day,id;
	bool operator<(const Node&o) const{return day>o.day;}
};

priority_queue<Node> Q;
int cnt[N];
bool chk(int x)
{
	while(!Q.empty()) Q.pop();
	for (int i=1;i<=n;i++) cnt[i]=0;
	for (int i=1;i<=n;i++) if (x<h[i]+a[i]*m) Q.push((Node){x/a[i],i});
	for (int i=1;i<=m;i++) for (int j=1;j<=k;j++)
	{
		if (Q.empty()) return 1;
		Node u=Q.top();Q.pop();
		if (u.day<i) return 0;
		cnt[u.id]++;
		if (x+cnt[u.id]*p<h[u.id]+a[u.id]*m) Q.push((Node){(x+cnt[u.id]*p)/a[u.id],u.id});
	}
	
	return Q.empty();
}
signed main()
{
	rd(n);rd(m);rd(k);rd(p);
	for (int i=1;i<=n;i++) {rd(h[i]);rd(a[i]);r=max(r,h[i]+a[i]*m);}
	while (l<=r) {int mid=(l+r)/2;if (chk(mid)) ans=mid,r=mid-1;else l=mid+1;}
	cout<<ans<<endl;
}