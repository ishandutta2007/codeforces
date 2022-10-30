#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int x=sqrt(n);
		while(n<=x*x) --x;
		n-=x*x;
		if(n<=x+1)
		{
			cout << n << " " << x+1 << "\n";
		}
		else cout << x+1 << " " << x+1-(n-x-1) << "\n";
	}
	return 0;
}