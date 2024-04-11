#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+2,M=1.2e6+2;
vector<int> bel[N];
int a[N];
int n;
struct seg
{
	int z,y,K,B,R,n;
	int l[M],r[M],k[M];
	ll mn[M],mx[M],b[M],a[N];
	void build(int x)
	{
		k[x]=1;b[x]=0;
		if (l[x]==r[x]) return mn[x]=mx[x]=a[l[x]],void();
		int c=x<<1;
		l[c]=l[x];r[c]=l[x]+r[x]>>1;
		l[c|1]=r[c]+1;r[c|1]=r[x];
		build(c);build(c|1);
		mn[x]=min(mn[c],mn[c|1]);
		mx[x]=max(mx[c],mx[c|1]);
	}
	void mdf(int x)
	{
		if (z<=l[x]&&r[x]<=y)
		{
			k[x]*=K;b[x]*=K;b[x]+=B;
			mn[x]=mn[x]*K+B;mx[x]=mx[x]*K+B;
			if (K<0) swap(mn[x],mx[x]);
			return;
		}
		int c=x<<1;
		if (k[x]!=1)
		{
			k[c]*=k[x];b[c]*=k[x];mn[c]*=k[x];mx[c]*=k[x];swap(mn[c],mx[c]);c^=1;
			k[c]*=k[x];b[c]*=k[x];mn[c]*=k[x];mx[c]*=k[x];swap(mn[c],mx[c]);c^=1;
			k[x]=1;
		}
		if (b[x]!=0)
		{
			b[c]+=b[x];mn[c]+=b[x];mx[c]+=b[x];c^=1;
			b[c]+=b[x];mn[c]+=b[x];mx[c]+=b[x];c^=1;
			b[x]=0;
		}
		if (z<=r[c]) mdf(c);
		if (y>r[c]) mdf(c|1);
		mn[x]=min(mn[c],mn[c|1]);
		mx[x]=max(mx[c],mx[c|1]);
	}
	void getr(int x)
	{
		if (mn[x]>=0||r[x]<=z||R!=n+1) return;
		if (l[x]==r[x]) return R=l[x],void();
		int c=x<<1;
		if (k[x]!=1)
		{
			k[c]*=k[x];b[c]*=k[x];mn[c]*=k[x];mx[c]*=k[x];swap(mn[c],mx[c]);c^=1;
			k[c]*=k[x];b[c]*=k[x];mn[c]*=k[x];mx[c]*=k[x];swap(mn[c],mx[c]);c^=1;
			k[x]=1;
		}
		if (b[x]!=0)
		{
			b[c]+=b[x];mn[c]+=b[x];mx[c]+=b[x];c^=1;
			b[c]+=b[x];mn[c]+=b[x];mx[c]+=b[x];c^=1;
			b[x]=0;
		}
		//printf("getr %d: [%d,%d] mn %lld mx %lld\n",x,l[x],r[x],mn[x],mx[x]);
		getr(c);getr(c|1);
	}
	void getl(int x)
	{
		//printf("getl %d: [%d,%d] mn %lld mx %lld %d\n",x,l[x],r[x],mn[x],mx[x],k[x]);
		if (mx[x]<=0||r[x]<=z||R!=n+1) return;
		if (l[x]==r[x]) return R=l[x],void();
		int c=x<<1;
		if (k[x]!=1)
		{
			k[c]*=k[x];b[c]*=k[x];mn[c]*=k[x];mx[c]*=k[x];swap(mn[c],mx[c]);c^=1;
			k[c]*=k[x];b[c]*=k[x];mn[c]*=k[x];mx[c]*=k[x];swap(mn[c],mx[c]);c^=1;
			k[x]=1;
		}
		if (b[x]!=0)
		{
			b[c]+=b[x];mn[c]+=b[x];mx[c]+=b[x];c^=1;
			b[c]+=b[x];mn[c]+=b[x];mx[c]+=b[x];c^=1;
			b[x]=0;
		}
		//printf("getl %d: [%d,%d] mn %lld mx %lld\n",x,l[x],r[x],mn[x],mx[x]);
		getl(c);getl(c|1);
	}
	void init(int nn)
	{
		n=r[l[1]=1]=nn;build(1);
	}
	void mdf(int l,int r,int k,int b)
	{
		z=l;y=r;K=k;B=b;mdf(1);
	}
	int find(int l,int typ)
	{
		z=l;R=n+1;
		if (typ>0) getr(1); else getl(1);
		return R;
	}
};
seg A,B;
int sum[N];
int main()
{
	//ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n;
		int id=0;
		int i,j;
		for (i=1;i<=n;i++) cin>>a[i];
		if (n==1)
		{
			cout<<(a[1]==0)<<'\n';continue;
		}
		for (i=1;i<=n;i++) sum[i]=a[i];
		static ll S[N];
		map<ll,int> ys;
		for (i=1;i<=n;i+=2) sum[i]=-sum[i];
		for (i=1;i<=n;i++) S[i]=S[i-1]+sum[i];
		for (i=2;i<=n;i++) sum[i]+=sum[i-1];
		for (i=1;i<=n;i+=2) A.a[i+1>>1]=sum[i];
		for (i=2;i<=n;i+=2) B.a[i>>1]=sum[i];
		A.init(n+1>>1);B.init(n>>1);
		ll ans=0;
		for (i=0;i<=n;i++)
		{
			if (!ys[S[i]]) ys[S[i]]=++id;
			bel[ys[S[i]]].push_back(i);
		}
		for (i=1;i<=n;i++)
		{
			A.mdf(1,n+1>>1,-1,a[i-1]);B.mdf(1,n>>1,-1,a[i-1]);
		//	cout<<A.find(i>>1,i&1?1:-1)<<' '<<B.find(i-1>>1,i&1?-1:1)<<endl;
			int R=min(A.find(i>>1,i&1?1:-1)*2-1,B.find(i-1>>1,i&1?-1:1)*2);
		//	for (j=1;j<=n;j++) sum[j]=a[i-1]-sum[j];
		//	for (j=i;j<R;j++) ans+=S[i-1]==S[j];
			auto &v=bel[ys[S[i-1]]];
			ans+=lower_bound(v.begin(),v.end(),R)-lower_bound(v.begin(),v.end(),i-1)-1;
			//cout<<i<<' '<<R<<' '<<ans<<endl;
			//for (j=1;j<=n;j++) cout<<sum[j]<<" \n"[j==n];
		}
		cout<<ans<<'\n';
		for (i=1;i<=id;i++) bel[i].clear();
	}
}
//1 0 1 0 0
//? 0 0 1 1