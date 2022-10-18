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
		int n,m,i,j,r=0;
		cin>>n;
		vector<int> a(n);
		for (int &x:a) cin>>x;
		for (i=1;i<n;i++) r+=a[i]==a[i-1];
		if (r<=1) {cout<<"0\n";continue;}
		r=0;
		for (i=1;i<n;i++) if (a[i]==a[i-1]) break;
		for (j=n-1;j;j--) if (a[j]==a[j-1]) break;
		cout<<max(j-i-1,1)<<'\n';
	}
}