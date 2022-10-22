#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

const int N = 2e5 + 5;
vector<int> g[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b), g[b].push_back(a);
	}
	vector<int> ord(n);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		--arr[i];
		ord[arr[i]] = i;
	}
	for (auto& x : g)
	{
		 sort(x.begin(), x.end(), [&](int a, int b)
				 {
				 	return ord[a] < ord[b];
				 });
	}
	if (arr[0] != 0)
	{
		 cout << "No\n";
		 return 0;
	}
	int st = arr[0];
	vector<int> q(1, st);
	vector<bool> used(n);
	used[st] = true;
	for (int i = 0; i < q.size(); ++i)
	{
		 int x = q[i];
		 for (int y : g[x])
			 if (!used[y])
				 used[y] = true, q.push_back(y);
	}
	if (q == arr)
		cout << "Yes\n";
	else
		cout << "No\n";


}