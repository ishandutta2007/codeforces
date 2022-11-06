//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

long long x, y, z, ans;

int main()
{
	cin>>x>>y;
	while(y)
	{
		ans += x / y;
		z = x % y;
		x = y;
		y = z;
	}
	cout<<ans<<endl;
	return 0;
}