#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

int main()
{
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int& x : a)
		cin >> x;
	vector<int> mem(101);
	for (int x : a)
		++mem[x];
	int cnt = accumulate(mem.begin(), mem.begin() + x, 0);
	int ans = x - cnt;
	ans += mem[x];
	cout << ans << endl;
}