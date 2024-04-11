#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200011;
typedef long long intl;
int a[N];
intl pre[N];

double calc(int p, int len, const int &n)
{
	int s = 1 + 2 * len;
	double mean = (pre[p] - pre[p - len - 1] + pre[n] - pre[n - len]) / (double)s;
	return mean - a[p];
}

double calc2(int p, int len, const int &n)
{
	int s = 2 + 2 * len;
	double mean = (pre[p + 1] - pre[p - len - 1] + pre[n] - pre[n - len]) / (double)s;
	double mid = (a[p] + a[p + 1]) / 2.0;
	return mean - mid;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	double c = 0;
	int t = 1;
	int p1, p2, p3, p4;
	int len;
	p1 = 1;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	pre[0] = 0;
	for(int i = 1; i <= n; i ++)
		pre[i] = pre[i - 1] + a[i];

	for(int i = 2; i < n; i ++)
	{
		//int now = 4 * (a[i - 1] + a[i] + a[n]) - 12 * a[i];
		int left = 1, right = min(i, n - i + 1);
		while(left + 1 < right)
		{
			int mid = (left + right) / 2;
			double change = calc(i, mid, n) - calc(i, mid - 1, n);
			if(change > 0)
				left = mid;
			else
				right = mid;
		}
		double now = calc(i, left, n);
		if(now > c)
		{
			t = 3;
			//p1 = i - 1;
			//p2 = i;
			//p3 = n;
			p1 = i;
			len = left;
			c = now;
		}
	}
	for(int i = 2; i < n - 1; i ++)
	{
		//int now = 3 * (a[i - 1] + a[i] + a[i + 1] + a[n]) - 6 * (a[i] + a[i + 1]);
		int left = 1, right = min(i, n - i);
		while(left + 1 < right)
		{
			int mid = (left + right) / 2;
			double change = calc2(i, mid, n) - calc2(i, mid - 1, n);
			if(change > 0)
				left = mid;
			else
				right = mid;
		}
		double now = calc2(i, left, n);
		if(now > c)
		{
			t = 4;
			//p1 = i - 1;
			//p2 = i;
			//p3 = i + 1;
			//p4 = n;
			p1 = i;
			p2 = i + 1;
			len = left;
			c = now;
		}
	}
	if(t == 1)
		cout << 1 << '\n' << a[p1] << '\n';
	else if(t == 3)
	{
		//cout << a[p1] << ' ' << a[p2] << ' ' << a[p3] << '\n';
		cout << 1 + 2 * len << '\n';
		for(int i = 1; i <= len; i ++)
			cout << a[n - i + 1] << ' ' << a[p1 - i] << ' ';
		cout << a[p1] << '\n';
	}
	else if(t == 4)
	{
		//cout << a[p1] << ' ' << a[p2] << ' ' << a[p3] << ' ' << a[p4] << '\n';
		cout << 2 + 2 * len << '\n';
		for(int i = 1; i <= len; i ++)
			cout << a[n - i + 1] << ' ' << a[p1 - i] << ' ';
		cout << a[p1] << ' ' << a[p2] << '\n';
	}
	return 0;
}