#include <iostream>
using namespace std;

const int N = 111;
const int M = 51111;
const int K = 311;

int a[N];

int dp1[M];
int dp2[M];

int cnt[K];
int l[K];
int r[K];

int main()
{
	ios :: sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	if(8 * n > t)
	{
		int ans = 0;
		for(int i = 0; i < n * t; i ++)
		{
			dp1[i] = 1;
			for(int j = max(0, i - n); j < i; j ++)
				if(a[i % n] >= a[j % n])
					dp1[i] = max(dp1[i], dp1[j] + 1);
			ans = max(ans, dp1[i]);
		}
		cout << ans << '\n';
	}
	else
	{
		t -= 8 * n;
		for(int i = 0; i < n; i ++)
			cnt[a[i]] ++;

		for(int i = 0; i < 4 * n * n; i ++)
		{
			dp1[i] = 1;
			for(int j = max(0, i - n); j < i; j ++)
				if(a[i % n] >= a[j % n])
					dp1[i] = max(dp1[i], dp1[j] + 1);
			l[a[i % n]] = max(l[a[i % n]], dp1[i]);
		}

		for(int i = 4 * n * n - 1; i >= 0; i --)
		{
			dp2[i] = 1;
			for(int j = min(4 * n * n - 1, i + n); j > i; j --)
				if(a[i % n] <= a[j % n])
					dp2[i] = max(dp2[i], dp2[j] + 1);
			r[a[i % n]] = max(r[a[i % n]], dp2[i]);
		}
		/*
		for(int i = 1; i <= 4; i ++)
			cout << l[i] << ' ' << r[i] << '\n';
		*/
		int ans = 0;
		for(int i = 0; i < K; i ++)
			ans = max(ans, l[i] + r[i] + cnt[i] * t);
		cout << ans << '\n';
	}
	return 0;
}