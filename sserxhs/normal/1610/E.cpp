#include <bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int a[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		int n,i,j,len,x,ans=0;
		cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=n;i=j)
		{
			j=i+1;
			while (j<=n&&a[i]==a[j]) ++j;
			len=j-i;x=j;
			while (x<=n)
			{
				++len;
				x=lower_bound(a+x+1,a+n+1,(a[x]<<1)-a[i])-a;
			}
			ans=max(ans,len);
		}
		cout<<n-ans<<'\n';
	}
}