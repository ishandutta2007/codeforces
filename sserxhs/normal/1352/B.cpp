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
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n>>m;
		if (n<m||m%2==1&&n%2==0&&n<2*m||n%2==1&&m%2==0) {cout<<"NO\n";continue;}
		cout<<"YES\n";
		if ((n-m)%2==0)
		{
			for (i=1;i<m;i++) cout<<1<<' ';
			cout<<n-m+1<<'\n';
		}
		else
		{
			for (i=1;i<m;i++) cout<<2<<' ';
			cout<<n-2*(m-1)<<'\n';
		}
	}
}