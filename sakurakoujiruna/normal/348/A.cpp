#include <bits/stdc++.h>
using namespace std;

const int N = 100011;
typedef long long ll;
ll a[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;

	for(int i = 0; i < n; i ++)
		cin >> a[i];

	ll left = *max_element(a, a + n);
	ll right = left * 2 + 1;
	ll sum = accumulate(a, a + n, 0LL);
	while(left + 1 < right)
	{
		ll mid = (left + right) / 2;
		if(n * (mid - 1) - sum >= mid - 1)
			right = mid;
		else
			left = mid;
	}
	cout << left << '\n';
	return 0;
}