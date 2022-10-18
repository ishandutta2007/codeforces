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
const int N=1e6+2;
int cnt[N];
ll tot[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j;
	ll ans=0;
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m)),b(m,vector<int>(n));
	for (auto &v:a) for (auto &x:v) cin>>x;
	for (i=0;i<n;i++) for (j=0;j<m;j++) b[j][i]=a[i][j];
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			ans+=(ll)cnt[a[i][j]]*i-tot[a[i][j]];
			++cnt[a[i][j]];
			tot[a[i][j]]+=i;
		}
	}
	swap(a,b);swap(n,m);
	memset(cnt,0,sizeof cnt);memset(tot,0,sizeof tot);
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			ans+=(ll)cnt[a[i][j]]*i-tot[a[i][j]];
			++cnt[a[i][j]];
			tot[a[i][j]]+=i;
		}
	}
	cout<<ans<<endl;
}