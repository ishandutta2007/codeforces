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
		int n,m,i,j,k,r=0,c=0,d=0,lst=0;
		cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		i=1,j=n;
		while (i<=j)
		{
			int cur=0;
			while (i<=j&&cur<=lst) cur+=a[i++];
			c+=cur;++r;lst=cur;
			if (i>j) break;cur=0;
			while (i<=j&&cur<=lst) cur+=a[j--];
			d+=cur;++r;lst=cur;
		}
		//r=r+1>>1;
		cout<<r<<' '<<c<<' '<<d<<'\n';
	}
}