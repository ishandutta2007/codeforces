#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
#define mid (l+r>>1)
 
using namespace std;
const int N=1000005;
typedef long long LL;
int n,tot;
LL m,a[N],pool[N],b[N],s[N],h[N];
vector <int> vt[N];
multiset <LL> sl,sr;
bool ans[N];
 
int find(int x)
{
	int l=1,r=tot;
	while(l<=r) pool[mid]<=x?l=mid+1:r=mid-1;
	return l-1;
}
 
void solve()
{
	scanf("%d%lld",&n,&m);
	tot=0;
	rep(i,1,n)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		pool[++tot]=a[i]-b[i];
		pool[++tot]=a[i];
		pool[++tot]=a[i]+b[i];
	}
	sort(pool+1,pool+1+tot);
	rep(i,1,tot) s[i]=0;
	rep(i,1,n)
	{
		int x=find(a[i]-b[i]);
		++s[x];
		x=find(a[i]);
		--s[x],--s[x];
		x=find(a[i]+b[i]);
		++s[x];
	}
	rep(i,1,tot) s[i]+=s[i-1],h[i]=0;
	rep(i,1,tot)
		h[i]=h[i-1]+s[i-1]*(pool[i]-pool[i-1]);
	rep(i,1,tot) h[i]=max(0ll,h[i]-m);
	rep(i,1,tot) vt[i].clear();
	rep(i,1,n)
	{
		int x=find(a[i]);
		vt[x].pb(i);
	}
	LL L=0,R=0;
	sl.clear();
	sr.clear();
	pool[tot+1]=pool[tot];
	rep(i,1,tot)
	{
		if(h[i]) sl.insert(h[i]-L);
		L+=pool[i+1]-pool[i];
	}
 
	repd(i,tot,1)
	{
		L-=pool[i+1]-pool[i];
		LL mx=0;
		if(!sl.empty()) mx=max(mx,*sl.rbegin()+L);
		if(!sr.empty()) mx=max(mx,*sr.rbegin()+R);
		for(auto x:vt[i])
		{
			if(b[x]>=mx) ans[x]=1;
			else ans[x]=0;
		}	
		if(h[i]) sl.erase(sl.find(h[i]-L));
		if(h[i]) sr.insert(h[i]-R);
		R+=pool[i]-pool[i-1];
	}
	rep(i,1,n) putchar('0'+ans[i]);
	puts("");
}
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}