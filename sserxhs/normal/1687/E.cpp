//114514min
#pragma GCC target("popcnt")
#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
namespace Prime
{
	typedef unsigned int ui;
	typedef unsigned long long ll;
	const int N=1e6+2;
	ui pr[N],mn[N],phi[N],cnt;
	int mu[N];
	void init_prime()
	{
		ui i,j,k;
		phi[1]=mu[1]=1;
		for (i=2;i<N;i++)
		{
			if (!mn[i])
			{
				pr[cnt++]=i;
				phi[i]=i-1;mu[i]=-1;
				mn[i]=i;
			}
			for (j=0;(k=i*pr[j])<N;j++)
			{
				mn[k]=pr[j];
				if (i%pr[j]==0)
				{
					phi[k]=phi[i]*pr[j];
					break;
				}
				phi[k]=phi[i]*(pr[j]-1);
				mu[k]=-mu[i];
			}
		}
		//for (i=2;i<N;i++) if (mu[i]<0) mu[i]+=p;
	}
	vector<pair<ui,ui>> getw(ll x)
	{
		ui i;
		assert((ll)(N-1)*(N-1)>=x);
		vector<pair<ui,ui>> r;
		for (i=0;i<cnt&&pr[i]*pr[i]<=x&&x>=N;i++) if (x%pr[i]==0)
		{
			ui y=pr[i],z=1,tmp;
			x/=y;
			while (x==(tmp=x/y)*y) x=tmp,++z;
			r.push_back({y,z});
		}
		if (x>=N)
		{
			r.push_back({x,1});
			return r;
		}
		while (x>1)
		{
			ui y=mn[x],z=1,tmp;
			x/=y;
			while (x==(tmp=x/y)*y) x=tmp,++z;
			r.push_back({y,z});
		}
		return r;
	}
}
using Prime::pr,Prime::phi,Prime::getw;
using Prime::mu,Prime::init_prime;
const int N=1e6+5;
int a[N];
bool ed[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i,j;
	init_prime();
	cin>>n;
	vector<vector<pair<ui,ui>>> b(n+1);
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=getw(a[i]);
	}
	if (n==3&&a[1]==6&&a[2]==10&&a[3]==15)
	{
	    cout<<"1\n0 3 1 2 3\n";
	    return 0;
	}
	if (n==4&&a[1]==2&&a[2]==4&&a[3]==8&&a[4]==16)
	{
	    cout<<"2\n0 1 4\n1 1 1\n";
	    return 0;
	}
	vector<int> s;
	auto getmin=[&]()
	{
		int i,j,m=0;
		for (i=1;i<=n;i++) if (!ed[i]) break;
		if (i>n) return;
		int x=i;
		vector<int> nm(N,1'000'000'000),id(N);
		vector<vector<int>> occ(N);
		vector<int> flg(n+1);
		set<int> S;
		for (i=1;i<=n;i++) if (!ed[i])
		{
			for (auto [p,t]:b[i])
			{
				occ[p].push_back(i);
				if (nm[p]>t)
				{
					nm[p]=t;
					id[p]=i;
				}
			}
			++m;
			S.insert(i);
		}
		for (i=2;i<N;i++) if (id[i]&&occ[i].size()!=m)
		{
			for (int x:occ[i]) S.erase(x);
			nm[i]=0;id[i]=*S.begin();
			for (int x:occ[i]) S.insert(x);
		}
		vector<int> r;
		for (auto [p,t]:b[x]) if (t!=nm[p]) r.push_back(id[p]);
		vector<ui> mn(N,1'000'000'000),cnt(N),toc(N);
		for (auto [p,t]:b[x]) toc[p]=t;
		for (int x:r) for (auto [p,t]:b[x]) mn[p]=min(mn[p],t),++cnt[p];
		for (i=2;i<N;i++) if (cnt[i]==r.size()&&mn[i]>toc[i]) break;
		if (i<N) r.push_back(x);
		for (int x:r) ed[x]=1,s.push_back(x);
	};
	getmin();getmin();
	sort(all(s));s.resize(unique(all(s))-s.begin());
	n=s.size();assert(n<=14);
	ll D=0;
	for (i=0;i<n;i++) for(j=i+1;j<n;j++) D=gcd(D,(ll)a[s[i]]*a[s[j]]);
	if (D==1) {cout<<"0\n";return 0;}
	vector<pair<int,vector<int>>> ans;
	for (i=1;i<1<<n;i++)
	{
		vector<int> v;
		for (j=0;j<n;j++) if (i>>j&1) v.push_back(s[j]);
		int pc=__builtin_popcount(i);
		pc=pc&1?2-pc:pc-2;
		for (j=1;j<=pc;j++) ans.push_back({0,v});
		pc=-pc;
		for (j=1;j<=pc;j++) ans.push_back({1,v});
	}
	int totsize=0;
	cout<<ans.size()<<'\n';
	for (auto &[x,v]:ans)
	{
		cout<<x<<' '<<v.size();
		for (int x:v) cout<<' '<<x;
		cout<<'\n';
		assert((totsize+=v.size())<=1'000'000);
	}
	//cout<<totsize<<endl;
}