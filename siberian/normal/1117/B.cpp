#include <bits/stdc++.h>

using namespace std;

#define int long long
int n, m, k;
vector <int> a;
void read()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	k++;
	int ans = a[0] * (k - 1) * (m / k);
	ans += a[1] * (m / k);
	ans += a[0] * (m % k);
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