#include <iostream>
using namespace std;

typedef long long intl;

const int N = 13;
int cnt[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		cnt[x] ++;
	}
	intl ans = 0;
	for(int i = 1; i <= m; i ++)
		ans += (intl)cnt[i] * (n - cnt[i]);
	cout << ans / 2 << '\n';
	return 0;
}