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
int a[N],s[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		ll tot=0;
		cin>>n>>m;
		fill_n(s,m+1,0);
		for (i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-a-1;
		for (i=1;i<=n;i++) s[a[i]]=1;
		for (i=2;i<=m;i++) s[i]+=s[i-1];
		for (i=1;i<=n;i++) for (j=1;j*a[i]<=m;j++) if (s[j]>s[j-1])
		{
			tot+=s[min(m,(j+1)*a[i]-1)]-s[j*a[i]-1];
		}
		if (tot==(ll)n*(n+1)/2) cout<<"Yes\n"; else cout<<"No\n";
	}
}