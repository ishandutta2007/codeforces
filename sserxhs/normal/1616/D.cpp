#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e5+2;
int a[N];
ll s[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n,i,j,x,lst=0,ans=0;
		cin>>n;
		for (i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
		cin>>x;j=0;
		for (i=1;i<=n;i++) if (a[i]<=x)
		{
			if (i!=j+1&&a[i]+a[i-1]<2*x||lst&&s[i]-s[lst-1]<(ll)x*(i-lst+1))
			{
				++ans;lst=0;j=i;continue;
			}
			lst=i;
		} else if (i!=j+1&&a[i]+a[i-1]<2*x)
		{
		
			++ans;lst=0;j=i;continue;
			
		}
		cout<<n-ans<<'\n';
	}
}