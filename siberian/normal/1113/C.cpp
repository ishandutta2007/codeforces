#include <bits/stdc++.h>

using namespace std;

#define int long long
int n;
const int MAXN = 3*1e5 + 10;
int arr[MAXN], x[MAXN];
	;
void read()
{
	cin >> n;
	x[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		x[i] = x[i - 1] ^ arr[i];
	}
//	for (int i = 1; i <= n; i++)
//		cout << x[i] << " ";
//	cout << endl;
}
int ans;
void run()
{
	map <int, int> fans1, fans2;
	for (int i = 0; i <= n; i++)
	{
		if (i % 2 == 0)
			fans1[x[i]]++;
		else
			fans2[x[i]]++;
	}
	ans = 0;
	for (auto i : fans1)
	{
		ans += i.second * (i.second - 1) / 2;
	}
	for (auto i : fans2)
	{
		ans += i.second * (i.second - 1) / 2;
	}
}

void write()
{
	cout << ans << endl;
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