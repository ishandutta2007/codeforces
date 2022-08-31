#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, M;
vector <int> edge[MAXN];
vector <int> res[MAXN];
bool seen[MAXN];
bool keep[MAXN];

map <ll, int> spec;
pair <int, int> elist[MAXN];

void flood (int cloc, int last)
{
	if (seen[cloc]) return;
	seen[cloc] = true;
	
	for (int i = 0; i < edge[cloc].size(); i++)
	{
		int neigh = edge[cloc][i];
		if (!seen[neigh])
		{
			keep[spec[cloc*(ll)MAXN+neigh]] = true;
			flood (neigh, cloc);
		}
	}
}

void flood2 (int cloc, int last)
{
	for (int i = 0; i < edge[cloc].size(); i++)
	{
		int neigh = edge[cloc][i];
		if (neigh != last)
			flood2 (neigh, cloc);
	}
	
	if (last != -1)
	{
		if (res[cloc].size() % 2 == 0)
			res[last].push_back (cloc);
		else
			res[cloc].push_back (last);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		
		edge[a].push_back (b);
		edge[b].push_back (a);
		elist[i] = make_pair (a, b);
		spec[a*(ll)MAXN+b] = i;
		spec[b*(ll)MAXN+a] = i;
	}
	
	if (M % 2)
	{
		cout << "No solution\n";
		return 0;
	}
	
	for (int i = 0; i < MAXN; i++)
		seen[i] = keep[i] = false;
	
	flood (0, -1);
	
	for (int i = 0; i < MAXN; i++)
		edge[i].clear();
	for (int i = 0; i < M; i++)
	{
		int a = elist[i].first, b = elist[i].second;
		if (keep[i])
		{
			edge[a].push_back (b);
			edge[b].push_back (a);
		}
		else
		{
			res[a].push_back (b);
		}
		
		//cout << i << " " << a << " " << b << " " << ((keep[i]) ? 1 : 0) << "\n";
		
	}
	
	flood2 (0, -1);
	
	/*for (int i = 0; i < N; i++)
		for (int j = 0; j < res[i].size(); j++)
			cout << i << " " << res[i][j] << "\n";
	*/
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < res[i].size() / 2; j++)
		{
			cout << res[i][2*j] + 1 << " " << i + 1 << " " << res[i][2*j+1] + 1 << "\n";
		}
	}
	return 0;
}