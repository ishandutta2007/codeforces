#include <bits/stdc++.h>

using namespace std;

//#define int long long
int n;
vector <int> a;
void read()
{
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		sum += x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	int ans = sum;
	for (int i = 2; i <= 100; i++)
	{
		for (int j = n - 1; j >= 1; j--)
		{
			if (a[j] % i == 0)
			{
				ans = min(ans, sum - a[0] - a[j] + a[0] * i + a[j] / i);
			}
		}
	}
	cout << ans << endl;
}

void run()
{
	
}

void write()
{
	
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}