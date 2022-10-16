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
int t,n,m;
char ans[1000001]; 
void solve()
{
	n=read();
	m=read();
	vector<pair<vector<int>,int>> a(n);
	vector<vector<int>> ul(n,vector<int>(m)),ur(n,vector<int>(m)),dl(n,vector<int>(m)),dr(n,vector<int>(m));
	for(int i=0;i<n;i++)
	{
		for(int l=0;l<m;l++)
			a[i].first.push_back(read());
		a[i].second=i;
	}
	sort(ALL(a));
	for(int i=0;i<n;i++)
		for(int l=0;l<m;l++)
		{
			ul[i][l]=a[i].first[l];
			if(i)
				ul[i][l]=max(ul[i][l],ul[i-1][l]);
			if(l)
				ul[i][l]=max(ul[i][l],ul[i][l-1]);
		}
	for(int i=0;i<n;i++)
		for(int l=m-1;l>=0;l--)
		{
			ur[i][l]=a[i].first[l];
			if(i)
				ur[i][l]=min(ur[i][l],ur[i-1][l]);
			if(l!=m-1)
				ur[i][l]=min(ur[i][l],ur[i][l+1]);
		}
	for(int i=n-1;i>=0;i--)
		for(int l=0;l<m;l++)
		{
			dl[i][l]=a[i].first[l];
			if(i!=n-1)
				dl[i][l]=min(dl[i][l],dl[i+1][l]);
			if(l)
				dl[i][l]=min(dl[i][l],dl[i][l-1]); 
		}
	for(int i=n-1;i>=0;i--)
		for(int l=m-1;l>=0;l--)
		{
			dr[i][l]=a[i].first[l];
			if(i!=n-1)
				dr[i][l]=max(dr[i][l],dr[i+1][l]);
			if(l!=m-1)
				dr[i][l]=max(dr[i][l],dr[i][l+1]);
		}
	for(int i=1;i<n;i++)
		for(int l=1;l<m;l++)
			if(ul[i-1][l-1]<dl[i][l-1]&&ur[i-1][l]>dr[i][l])
			{
				puts("YES");
				for(int j=0;j<i;j++)
					ans[a[j].second]='B';
				for(int j=i;j<n;j++)
					ans[a[j].second]='R';
				for(int j=0;j<n;j++)
					cout<<ans[j];
				cout<<" "<<l<<endl;
				return ;
			}
	puts("NO");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}