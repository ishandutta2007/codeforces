#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int p;
	cin >> p;
	int ans = 0;
	for(int i = 1; i < p; i ++)
	{
		bool flag = true;
		for(int j = 1, mul = i; j < p - 1; j ++, mul = mul * i % p)
			if(mul == 1)
				flag = false;
		ans += flag;
	}
	cout << ans << '\n';
	return 0;
}