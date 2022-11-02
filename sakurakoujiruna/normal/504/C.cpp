#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100011;
typedef long long intl;
int a[N];
int cnt[N];
int now[N];
bool wrong[N];

bool check(int* a, bool* wrong, int n, int m)
{
	//cout << n << ' ' << m << '\n';
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i <= m; i ++)
		cnt[a[i]] ++;
	if(m < n / 2)
		for(int i = m + 1; i < n / 2; i ++)
			if(a[i] != a[n - i - 1])
				return false;
	int c = min(m, n - m - 2);
	for(int i = 0; i <= c; i ++)
	{
		int t = a[n - i - 1];
		if(cnt[t] == 0)
			return false;
		cnt[t] --;
	}
	return true;
}

int solve(int* a, bool* wrong, int n)
{
	int left = 0, right = n;
	while(left + 1 < right)
	{
		int mid = (left + right) / 2;
		if(check(a, wrong, n, mid - 1))
			right = mid;
		else
			left = mid;
	}
	//cout << left << '\n';
	return left;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		cnt[a[i]] ++;
	}
	int odd_cnt = 0;
	int odd;
	for(int i = 1; i <= n; i ++)
		if(cnt[i] & 1)
		{
			odd = i;
			odd_cnt ++;
		}
	if(odd_cnt > 1)
	{
		cout << 0 << '\n';
		return 0;
	}
	bool flag = false;
	for(int i = 1; i <= n; i ++)
		if(a[i] != a[n - i + 1])
		{
			wrong[i] = true;
			flag = true;
		}
	if(!flag)
	{
		cout << (intl)n * (n + 1) / 2 << '\n';
		return 0;
	}
	if((n & 1) && a[n / 2 + 1] != odd)
		wrong[n / 2 + 1] = true;
	for(int i = 1; i <= n; i ++)
		if(wrong[i])
		{
			intl ans = (intl)n * (n + 1) / 2;
			ans -= (intl)(n - 2 * i) * (n - 2 * i + 1) / 2;
			ans -= (intl)i * (i - 1);
			ans -= (intl)i * solve(a + i, wrong + i, n - 2 * (i - 1));
			reverse(a + i, a + (n - i + 1) + 1);
			ans -= (intl)i * solve(a + i, wrong + i, n - 2 * (i - 1));
			cout << ans << '\n';
			return 0;
		}
	return 0;
}