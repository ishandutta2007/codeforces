#include "bits/stdc++.h"
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
	int T;cin>>T;
	while (T--)
	{
		int n,m,i;
		cin>>n>>m;
		vector<int> a(n);
		for (int &x:a) cin>>x;
		int mn=*min_element(all(a)),mx=*max_element(all(a));
		ll cur=0;
		for (i=1;i<n;i++) cur+=abs(a[i]-a[i-1]);
		if (mn>1) cur+=min({mn*2-2,a[0]-1,a[n-1]-1});
		if (mx<m) cur+=min({m*2-mx*2,m-a[0],m-a[n-1]});
		cout<<cur<<'\n';
	}
}