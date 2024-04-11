#include <bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int a[N],b[N],c[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		int n,i,j,x,y,m;
		cin>>n;
		for (i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		i=1;j=n;
		while (i<j&&a[i]==a[j]) ++i,--j;
		if (i>=j) goto yes;
		x=a[i];y=a[j];
		m=0;
		for (i=1;i<=n;i++) if (a[i]!=x) b[++m]=a[i];
		for (i=1;i<=m;i++) if (b[i]!=b[m-i+1]) break;
		if (i>m) goto yes;
		m=0;
		for (i=1;i<=n;i++) if (a[i]!=y) b[++m]=a[i];
		for (i=1;i<=m;i++) if (b[i]!=b[m-i+1]) break;
		if (i>m) goto yes;
		cout<<"NO\n";continue;
		yes:cout<<"YES\n";
	}
}