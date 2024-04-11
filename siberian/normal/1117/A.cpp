#include <bits/stdc++.h>

using namespace std;

#define int long long
int n;
vector <int> a;
void read()
{
	cin >> n;
	int mx = -1e18;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x); 
		mx = max(mx, x);
	}
	int ans = 1;
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == mx)
			len++;
		else
			len = 0;
		ans = max(len, ans);
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