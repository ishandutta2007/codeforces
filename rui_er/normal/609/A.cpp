//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int a[101];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1, a+1+n, greater<int>());
	for(int i=1;i<=n;i++)
	{
		m -= a[i];
		++ans;
		if(m <= 0)
		{
			cout<<ans<<endl;
			return 0;
		}
	}
	return 0;
}