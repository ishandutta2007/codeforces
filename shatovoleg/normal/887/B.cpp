#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> cubes;
vector<int> used;
set<int> pos;

int cur = 0;

void gen(int n)
{
	pos.insert(cur);
	if (n >= cubes.size())
		return;
	for (int i = 0; i < cubes.size(); ++i)
		if (!used[i])
		{
			used[i] = 1;
			for (auto x : cubes[i])
			{
				cur *= 10;
				cur += x;
				gen(n + 1);
				cur /= 10;
			}
			used[i] = 0;
		}
}

int main()
{
	int n;
	cin >> n;
	cubes.resize(n, vector<int>(6));
	used.resize(n, 0);
	for (auto &v : cubes)
		for (auto &x : v)
			cin >> x;
	gen(0);
	for (int i = 1; ; ++i)
		if (!pos.count(i))
		{
			cout << i - 1 << endl;
			return 0;
		}
}