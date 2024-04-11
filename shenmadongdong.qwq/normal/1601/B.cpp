#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define rep_(i,a,b) for(int i=(a);i<(b).size();++i)
#define F(a) rep(a,1,n)
#define M(a,b) memset(a,b,sizeof a)
#define DC int T;cin>>T;while(T--)
#define ll long long
#define Z(a,b) sort(a+1,a+b+1)
using namespace std;
const int mod=998244353;
const int _mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
template <typename T> void rd(T &x){x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch==45)f=-1;ch=getchar();}while(isdigit(ch))x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y){if(y&1)ret=ret*x;y>>=1;x=x*x;}return ret;}
/*
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int n,b[300010],nxt[300010];
vector<int> pre[300010],ans;
pair<int,int> a[300010];
int main()
{
	cin>>n;
	F(i) rd(a[i].first),a[i].second=i;
	F(i) a[i].first=a[i].second-a[i].first;
	F(i) rd(b[i]);
	F(i) pre[i+b[i]].push_back(i);
	Z(a,n);
	F(i) a[i].first=-a[i].first+a[i].second;
	int s=0,p=1;
	bool f=1;
	F(i) nxt[i]=-1;
	while(f) 
	{
		int q=0;
		f=0;
		while(a[p].second-a[p].first<=s&&p<=n) 
		{
			f=1;
			nxt[a[p].second]=s;
			for(int x:pre[a[p].second]) q=max(q,x);
			p++;
		}
		s=q;
	}
  	if (nxt[n]==-1) return puts("-1"),0;
  	for(int i=nxt[n];i;i=nxt[i]) ans.push_back(i),i+=b[i];
	cout<<ans.size()+1<<'\n';
	rep_(i,0,ans) cout<<ans[i]<<' ';
	puts("0");
	return 0;
}