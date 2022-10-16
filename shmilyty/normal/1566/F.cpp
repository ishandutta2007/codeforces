#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int t,n,m,a[2<<17],mR[2<<17];
vector<pair<int,int> > v;
void solve()
{
	n=read();
	m=read();
	for(int i=0;i<n;i++)
		a[i]=read();
	a[n++]=INF;
	a[n++]=-INF;
	sort(a,a+n);
	v.clear();
	while(m--)
	{
		int l=read(),r=read();
		int id=lower_bound(a,a+n,l)-a;
		if(id<n&&a[id]<=r)
			continue;
		v.push_back({l,r});
	}
	sort(v.begin(),v.end());
	int f0=0,f1=0,L=0;
	for(int i=0;i+1<n;i++)
	{
		int R=L;
		while(R<v.size()&&v[R].second<a[i+1])
			R++;
		mR[R]=a[i+1];
		for(int l=R-1;l>=L;l--)
			mR[l]=min(mR[l+1],v[l].second);
		int nf0=INF,nf1=INF;
		for(int l=L;l<=R;l++)
		{
			int ll=l==L?0:v[l-1].first-a[i],r=a[i+1]-mR[l];
			nf0=min({nf0,f0+ll+r*2,f1+ll*2+r*2});
			nf1=min({nf1,f0+ll+r,f1+ll*2+r});	
		}
		f0=nf0;
		f1=nf1;
		L=R;
	}
	cout<<min(f1,f0)<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}