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
const int N=1e6+5;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j,k,r;
	cin>>n;
	//assert(n<=10);
	if (n<=2) {cout<<"1\n1 1\n";return 0;}
	if (n==3) {cout<<"2\n1 1\n1 2\n";return 0;}
	if (n==4) {cout<<"3\n1 1\n1 2\n1 3\n";return 0;}
	vector<pair<int,int>> a(1,{1,1});
	i=j=1;
	if (n%3==0) a.push_back({n,n}),--n;
	for (int k=1;k<=(n-1)/3;k++)
	{
		i++;j+=2;
		a.push_back({i,j});
	}
	i++;j=2;
	for (int k=1;k<=(n-1)/3;k++)
	{
		a.push_back({i,j});
		assert(i<=n&&j<=n);
		i++;j+=2;
	}
/*
1 2 3 4 5 6 7 8 9
1 1 2 3 3 4 5 5 6
122222222
221222222
222212222
212222222
222122222
222222220
222222222
222222222
222220222
*/
	/*i=3,j=2;
	int d=0;
	while (i<=n)
	{
		a.push_back({i,j}),a.push_back({j,i});
		i+=3-d,j+=2-d;
		d=1;
	}*/
	//a.pop_back();a.pop_back();
	cout<<a.size()<<'\n';
	for (auto [x,y]:a) cout<<x<<' '<<y<<'\n';
	/*int b[n+1][n+1]={};
	for (auto [x,y]:a) b[x][y]=1;
	for (i=1;i<=n;i++) for (j=1;j<=n;j++) if (b[i][j]==1)
	{
		for (k=1;k<=n;k++) if (!b[i][k]) b[i][k]=2;
		for (k=1;k<=n;k++) if (!b[k][j]) b[k][j]=2;
		for (k=1;i+k<=n&&j+k<=n;k++) if (!b[i+k][j+k]) b[i+k][j+k]=2;
	}
	for (i=1;i<=n;i++) {for (j=1;j<=n;j++) cerr<<b[i][j];cerr<<'\n';}*/
	/*int a[n][n];
	for (ll s=0;s<1ll<<n*n;s++) if (__builtin_popcount(s)<=4)
	{
		for (i=0;i<n;i++) for (j=0;j<n;j++) a[i][j]=s>>i*n+j&1;
		for (i=0;i<n;i++) for (j=0;j<n;j++) if (a[i][j]==1)
		{
			for (k=0;k<n;k++) if (!a[i][k]) a[i][k]=2;
			for (k=0;k<n;k++) if (!a[k][j]) a[k][j]=2;
			for (k=0;i+k<n&&j+k<n;k++) if (!a[i+k][j+k]) a[i+k][j+k]=2;
		}
		for (i=0;i<n;i++) for (j=0;j<n;j++) if (!a[i][j]) goto no;
		if (__builtin_popcount(s)<__builtin_popcount(r)) {r=s;break;}
		no:;
	}
	for (i=0;i<n;i++) for (j=0;j<n;j++) a[i][j]=r>>i*n+j&1;
	for (i=0;i<n;i++) {for (j=0;j<n;j++) cerr<<a[i][j];cerr<<endl;}*/
}