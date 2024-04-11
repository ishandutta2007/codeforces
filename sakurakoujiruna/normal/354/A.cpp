#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100011;
typedef long long intl;

int w[N];
intl sum[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, l, r, ql, qr;
	cin >> n >> l >> r >> ql >> qr;
	for(int i = 1; i <= n; i ++)
		cin >> w[i];
	
	//sort(w + 1, w + n + 1);
	for(int i = 1; i <= n; i ++)
		sum[i] = sum[i - 1] + w[i];
	/*
	if(l < r)
	{
		swap(l, r);
		swap(ql, qr);
	}
	*/

	intl ans = (intl)1e18;
	for(int i = 0; i <= n; i ++)
	{
		intl ls = sum[i];
		intl rs = sum[n] - sum[i];
		intl sp = 0;
		intl a = i;
		intl b = n - i;
		if(a > b + 1)
			sp = (a - b - 1) * ql;
		else if(b > a + 1)
			sp = (b - a - 1) * qr;
		ans = min(ans, sp + ls * l + rs * r);
	}
	cout << ans << '\n';
	return 0;
}