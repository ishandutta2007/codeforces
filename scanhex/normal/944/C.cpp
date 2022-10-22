#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;
typedef long double db;
typedef complex<db> cp;

vector<vector<int>> ch;
vector<int> de;

int d(int u)
{
	for (int v : ch[u])
		de[v] = de[u] + 1, d(v);
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> p(n);
	ch.resize(n);
	for (int i = 1; i < n; ++i)
	{
		cin >> p[i];
		--p[i];
		ch[p[i]].push_back(i);
	}
	de.resize(n);
	d(0);
	vector<int> ans(n);
	for (int i = 0; i < n; ++i)
		ans[de[i]] ^= 1;
	cout << accumulate(ans.begin(), ans.end(), 0) << '\n';
}