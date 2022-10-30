#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const double pi = 2.0 * acos(0.0);

void solve(vector < vector < int > > g) {
	int n = g.size();
	vector<int> deg (n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			deg[i] += g[i][j];

	int first = 0;
	while (!deg[first])  ++first;

	int v1 = -1,  v2 = -1;
	bool bad = false;
	for (int i=0; i<n; ++i)
		if (deg[i] & 1)
			if (v1 == -1)
				v1 = i;
			else if (v2 == -1)
				v2 = i;
			else
				bad = true;

	if (v1 != -1)
		++g[v1][v2],  ++g[v2][v1];

	stack<int> st;
	st.push (first);
	vector<int> res;
	while (!st.empty())
	{
		int v = st.top();
		int i;
		for (i=0; i<n; ++i)
			if (g[v][i])
				break;
		if (i == n)
		{
			res.push_back (v);
			st.pop();
		}
		else
		{
			--g[v][i];
			--g[i][v];
			st.push (i);
		}
	}

	if (v1 != -1)
		for (size_t i=0; i+1<res.size(); ++i)
			if (res[i] == v1 && res[i+1] == v2 || res[i] == v2 && res[i+1] == v1)
			{
				vector<int> res2;
				for (size_t j=i+1; j<res.size(); ++j)
					res2.push_back (res[j]);
				for (size_t j=1; j<=i; ++j)
					res2.push_back (res[j]);
				res = res2;
				break;
			}

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (g[i][j])
				bad = true;

	for (size_t i=0; i<res.size(); ++i)
		printf ("%d ", res[i]+1);
	printf("\n");
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector < pair < double, double > > p;
	for (int i = 0; i < 5; ++i) {
		double r = 5.0 / sin(pi / 5.0);
		double ang = 2.0 * pi / 5.0;
		double x = r * cos(pi / 2.0 + ang * i);
		double y = r * sin(pi / 2.0 + ang * i);
		p.push_back(make_pair(x, y));
	}

	double shift = p[4].first - p[1].first;
	double add = 0.0;
	vector < vector < int > > a;
	a.push_back(vector < int > ());
	for (int i = 0; i < 5; ++i) {
		a[0].push_back(i);
	}
	for (int i = 1; i < n; ++i) {
		add += shift;
		vector < int > b;
		for (int j = 0; j < 5; ++j) {
			pair < double, double > cur = p[j];
			cur.first += add;
			if (j != 1) {
				b.push_back(p.size());
				p.push_back(cur);
			} else {
				b.push_back(p.size() - 2);
			}
		}
		a.push_back(b);
	}

	printf("%d\n", 5 * n - (n - 1));
	for (int i = 0; i < p.size(); ++i) {
		printf("%.10lf %.10lf\n", p[i].first, p[i].second);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			printf("%d ", a[i][j] + 1);
		}
		printf("\n");
	}

	vector < vector < int > > g(p.size(), vector < int > (p.size(), 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			int x = a[i][j];
			int y = a[i][(j + 2) % 5];
			g[x][y] = g[y][x] = 1;
		}
	}
	solve(g);

	return 0;
}