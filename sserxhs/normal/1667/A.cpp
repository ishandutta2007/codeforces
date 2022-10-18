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
int a[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j;
	ll r=1e18,cur=0;
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	for (j=1;j<=n;j++)
	{
		ll now=0;cur=0;
		for (i=j-1;i;i--) cur+=now/a[i]+1,now=(now/a[i]+1)*a[i];
		now=0;
		for (i=j+1;i<=n;i++) cur+=now/a[i]+1,now=(now/a[i]+1)*a[i];
		r=min(r,cur);
	}
	cout<<r<<endl;
}