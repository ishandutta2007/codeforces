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
		int x,y,z,n,i,j;
		cin>>x>>y>>z;n=x+y+z+1;
		if (!y)
		{
			assert(!x||!z);
			for (i=1;i<=n;i++) a[i]=!!z;
			for (i=1;i<=n;i++) cout<<a[i];
			cout<<'\n';
			continue;
		}
		for (i=1;i<=x+1;i++) a[i]=0;
		a[x+2]=1;
		int t=x+2;
		for (i=1;i<=y-2;i+=2) a[x+2+i]=0,a[x+3+i]=1,t=max(t,x+3+i);
		x=t+1;
		for (i=1;i<=z;i++) a[x++]=1;
		if (y%2==0) cout<<1,--n;
		for (i=1;i<=n;i++) cout<<a[i];
		cout<<'\n';
	}
}