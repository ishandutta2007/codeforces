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
const int MAXN = 200100;

int N;
pair <int, int> event[MAXN]; // loc, #
vector <int> edge[MAXN];
bool seen[MAXN];
int res[MAXN];

void flood (int cloc, int cval)
{
	if (seen[cloc]) return;
	seen[cloc] = true;
	res[cloc] = cval;
	
	for (int i = 0; i < edge[cloc].size(); i++)
		flood (edge[cloc][i], 1 - cval);
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int l, r;
		cin >> l >> r;
		
		event[2*i] = make_pair (2 * l, 2*i);
		event[2*i+1] = make_pair (2 * r + 1, 2*i+1);
		
		edge[2*i].push_back(2*i+1);
		edge[2*i+1].push_back(2*i);
	}
	
	sort (event, event + 2 * N);
	
	for (int i = 0; i < N; i++)
	{
		int l = event[2*i].second, r = event[2*i+1].second;
		edge[l].push_back (r);
		edge[r].push_back (l);
	}
	
	for (int i = 0; i < 2 * N; i++)
	{
		seen[i] = false;
		res[i] = 0;
	}
	
	for (int i = 0; i < 2 * N; i++)
		if (!seen[i])
			flood (i, 0);
	
	for (int i = 0; i < N; i++)
	{
		if (i) cout << " ";
		cout << res[2*i];
	}
	cout << "\n";
	return 0;
}