#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	vector<bool> was(n, false);
	int cnt = n + 1;
	for (int x : a)
		if (!was[x])
			was[x] = true, --cnt;
	cout << cnt << endl;
}