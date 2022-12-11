#include <bits/stdc++.h>

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define all(a) a.begin(), a.end()
#define sqr(a) ((a)*(a))

const double eps = 1e-9;
const int nmax = 200200;

vector<int> g[nmax];

int main() {
	int n, k;
	cin >> n >> k;
	int m = k;


	for (int i = 0; i < k; i ++)
		g[i].push_back(m);
	int now = 0;

	for (int j = m + 1; j < n; j ++)
		g[j % k].push_back(j);

	for (int i = 0; i < k; i ++)
		g[i].push_back(i);

	vector<int> temp;
	for (int i = 0; i < k; i ++)
		temp.push_back(-g[i].size());
	sort(all(temp));	
	cout << -temp[0] - temp[1] - 2 << endl;
	for (int i = 0; i < k; i ++)
		for (int j = 0; j < g[i].size() - 1; j ++)
			printf("%d %d\n", g[i][j] + 1, g[i][j+1] + 1);
		

	return 0;
}