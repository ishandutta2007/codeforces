#include <bits/stdc++.h>

using namespace std;
vector<int> p;

struct cmp
{
	bool operator()(int a, int b)
	{
		if (p[a] != p[b])
			return p[a] < p[b];
		return a < b;
	}
};

int main()
{
	int n;
	scanf("%d", &n);
	p.resize(n);
	vector<vector<int>> col(2, vector<int>(n));
	for (int& x : p)
		scanf("%d", &x);
	for (int& x : col[0])
		scanf("%d", &x), --x;
	for (int& x : col[1])
		scanf("%d", &x), --x;
	int m;
	scanf("%d", &m);
	vector<int> c(m);
	for (int& x : c)
		scanf("%d", &x), --x;
	vector<set<int, cmp>> keks(3);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 2; ++j)
			keks[col[j][i]].insert(i);
	for (int x : c)
	{
		if (keks[x].size() == 0)
			cout << -1 << ' ';
		else
		{
			int ind = *keks[x].begin();
			for (int j = 0; j < 2; ++j)
				keks[col[j][ind]].erase(ind);
			cout << p[ind] << ' ';
		}
	}
	cout << endl;
}