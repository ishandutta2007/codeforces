#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int init[MAXN];
int goal[MAXN];
vector <int> edge[MAXN];

vector <int> res;

void flood (int cloc, int last, int cpar, int apar) // cur parity, other parity
{
	if (init[cloc] ^ goal[cloc] != cpar)
	{
		cpar ^= 1;
		res.push_back (cloc);
	}
	
	for (int i = 0; i < edge[cloc].size(); i++)
	{
		int neigh = edge[cloc][i];
		if (neigh == last) continue;
		
		flood (neigh, cloc, apar, cpar);
	}
}

int main()
{
	ios_base::sync_with_stdio (0);
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		
		edge[u].push_back (v);
		edge[v].push_back (u);
	}
	
	for (int i = 0; i < N; i++)
		cin >> init[i];
	for (int i = 0; i < N; i++)
		cin >> goal[i];
	
	flood (0, -1, 0, 0);
	
	sort (res.begin(), res.end());
	
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++)
		cout << res[i] + 1 << "\n";
	return 0;
}