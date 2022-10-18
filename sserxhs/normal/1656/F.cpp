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
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,t;
		ll r=-1e18,k=0,b=0;
		cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		if (accumulate(a+1,a+n+1,0ll)+a[1]*(n-2ll)>0||a[n]*(n-2ll)+accumulate(a+1,a+n+1,0ll)<0)
		{
			cout<<"INF\n";
			continue;
		}
		for (i=2;i<=n;i++) b+=(ll)a[i]*a[1],k+=a[i]+a[1];
		t=-a[1];
		r=k*t+b;
		for (i=2;i<n;i++)
		{
			k+=a[n]-a[1];
			b+=(ll)a[i]*(a[n]-a[1]);
			t=-a[i];
			r=max(r,k*t+b);
		}
		t=-a[n];
		r=max(r,k*t+b);
		cout<<r<<'\n';
	}
}