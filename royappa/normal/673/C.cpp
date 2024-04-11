#include <bits/stdc++.h>

//http://codeforces.com/contest/673/problem/C

using namespace std;


typedef long long LL;

typedef pair<int,int> pi;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int dom[5001], colcount[5001];
	memset(dom, 0, sizeof(dom));
	for (int i = 0; i < n; i++)
	{
		memset(colcount, 0, sizeof(colcount));
		int bestCol = 5001, best = 0;
		for (int j = i; j < n; j++)
		{
			int c = v[j];
			colcount[c]++;
			if (colcount[c] > best || (colcount[c] == best && c < bestCol))
			{
				bestCol = c;
				best = colcount[c];
			}
			dom[bestCol]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << dom[i];
		if (i != n) cout << " ";
	}
	cout << endl;
	exit(0);
}