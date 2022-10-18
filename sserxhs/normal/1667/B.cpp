#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5,inf=1e9;
int a[N],mx[N][2];
ll s[N],b[N];
int f[N][2];
template<typename typC> struct bit
{
	vector<typC> _a;
	typC *a;
	int n;
	bit(){}
	bit(int nn)
	{
		n=nn++;
		_a.resize(nn);a=_a.data();
		fill(all(_a),-inf);
	}
	void mdf(int x,typC y)
	{
		a[x]=max(a[x],y);
		while ((x+=x&-x)<=n) a[x]=max(a[x],y); 
	}
	typC sum(int x)
	{
		typC r=a[x];
		while (x^=x&-x) r=max(r,a[x]);
		return r;
	}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,r=0;
		cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		vector<ll> b(s,s+n+1);
		sort(all(b));b.resize(unique(all(b))-b.begin());
		for (i=0;i<=n;i++) s[i]=lower_bound(all(b),s[i])-b.begin()+1;
		//for (i=0;i<=n;i++) cerr<<s[i]<<" \n"[i==n];
		bit<int> t0(b.size()),t1(b.size());
		for (i=1;i<=b.size();i++) mx[i][0]=mx[i][1]=-inf;
		f[0][0]=0;f[0][1]=0;mx[s[0]][0]=mx[s[0]][1]=0;
		t0.mdf(s[0],0);t1.mdf(s[0],0);
		for (i=1;i<=n;i++)
		{
			f[i][0]=max(mx[s[i]][1],t1.sum(s[i]-1)+i);
			//if (i==2) dbgn(mx[s[i]][1],t1.sum(s[i]-1)+i);
			f[i][1]=max(mx[s[i]][0],t0.sum(b.size())-i);
			t0.mdf(s[i],f[i][0]+i);t1.mdf(s[i],f[i][1]-i);
			mx[s[i]][0]=max(mx[s[i]][0],f[i][0]);
			mx[s[i]][1]=max(mx[s[i]][1],f[i][1]);
		//	dbg(i,f[i][0],f[i][1]);
		}
		cout<<max(f[n][0],f[n][1])<<'\n';
	}
}