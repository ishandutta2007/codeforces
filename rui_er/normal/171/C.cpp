//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		ans += k * i;
	}
	cout<<ans<<endl;
	return 0;
}