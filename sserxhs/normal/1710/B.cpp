//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream & operator>>(istream &cin,pair<typC,typD> &a) {return cin>>a.first>>a.second;}
template<typename typC> istream & operator>>(istream &cin,vector<typC> &a){for (auto &x:a) cin>>x;return cin;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a){for (auto &x:a) cout<<x<<'\n';return cout;}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a){int n=a.size();if (!n) return cout;cout<<a[0];for (int i=1;i<n;i++) cout<<' '<<a[i];return cout;}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
vector<int> lg(2);
template <typename T> struct maxtable
{
	vector<T> a;
	vector<vector<T>> st;
	maxtable(const vector<T> &b):a(all(b))
	{
		int n=a.size(),i,j,k,r;
		while (lg.size()<=n) lg.push_back(lg[lg.size()>>1]+1);
		st.assign(lg[n]+1,vector<T>(n));
		iota(all(st[0]),0);
		for (j=1;j<=lg[n];j++)
		{
			r=n-(1<<j);
			k=1<<j-1;
			for (i=0;i<=r;i++) st[j][i]=a[st[j-1][i]]<a[st[j-1][i+k]]?st[j-1][i+k]:st[j-1][i];
		}
	}
	T rmq(int l,int r) const
	{
		if (l>r) return -1e18;
		assert(0<=l&&l<=r&&r<a.size());
		int z=lg[r-l+1];
		return max(a[st[z][l]],a[st[z][r-(1<<z)+1]]);
	}
	int rmp(int l,int r) const
	{
		assert(0<=l&&l<=r&&r<a.size());
		int z=lg[r-l+1];
		return a[st[z][l]]<a[st[z][r-(1<<z)+1]]?st[z][r-(1<<z)+1]:st[z][l];
	}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n>>m;
		vector<ll> x(n),p(n);
		for (i=0;i<n;i++) cin>>x[i]>>p[i];
		vector<ll> a=x;
		vector<ll> k(n+1),b(n+1);
		sort(all(a));a.push_back(2.000001e9);
		for (i=0;i<n;i++)
		{
			int L=x[i]-p[i],R=x[i]+p[i];
			int M=lower_bound(all(a),x[i])-a.begin();
			int l=lower_bound(all(a),L)-a.begin(),r=upper_bound(all(a),R)-a.begin();
			++k[l];k[M+1]-=2;++k[r];
			b[l]-=a[l]-(p[i]-abs(x[i]-a[l]));b[M+1]+=a[l]-(p[i]-abs(x[i]-a[l]));
			b[M+1]+=a[M+1]+(p[i]-abs(a[M+1]-x[i]));b[r]-=a[M+1]+(p[i]-abs(a[M+1]-x[i]));
		}
		for (i=0;i<n;i++) k[i+1]+=k[i],b[i+1]+=b[i];
		// for (i=0;i<n;i++) cerr<<k[i]<<' '<<b[i]<<'\n';
		string ans(n,'0');
		vector<ll> c(n),sc(n+1),sd(n+1),e(n),f(n);
		for (i=0;i<n;i++) c[i]=k[i]*a[i]+b[i],e[i]=c[i]-a[i],f[i]=c[i]+a[i];
		maxtable s(e),t(f);
		sc[0]=0;
		for (i=0;i<n;i++) sc[i+1]=max(sc[i],c[i]);
		sd[n]=0;
		for (i=n-1;i>=0;i--) sd[i]=max(sd[i+1],c[i]);
		// dbg(c);
		for (i=0;i<n;i++)
		{
			int L=x[i]-p[i],R=x[i]+p[i];
			int M=lower_bound(all(a),x[i])-a.begin();
			int l=lower_bound(all(a),L)-a.begin(),r=upper_bound(all(a),R)-a.begin();
			// dbgn(sc[l],sd[r],s.rmq(l,M)+a[l]+(p[i]-abs(x[i]-a[l])),t.rmq(M,r-1)-(a[r-1]+(p[i]-abs(x[i]-a[r-1]))));
			if (max(sc[l],sd[r])<=m&&(l==r||s.rmq(l,M)+L<=m&&t.rmq(M,r-1)-R<=m))
				ans[i]='1';
		}
		cout<<ans<<'\n';
	}
}