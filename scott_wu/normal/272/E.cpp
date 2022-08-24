#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N, M;
vector <int> edge[MAXN];
priority_queue <pair <int, int> > pq;
bool res[MAXN];
int deg[MAXN];

void fix (int x)
{
	deg[x] = 0;
	for (int i = 0; i < edge[x].size(); i++)
		if (res[edge[x][i]] == res[x])
			deg[x]++;
	pq.push (make_pair (deg[x], x));
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back (b);
		edge[b].push_back (a);
	}
	
	for (int i = 0; i < N; i++)
		res[i] = false; //all in 0
	
	for (int i = 0; i < N; i++)
	{
		deg[i] = edge[i].size();
		pq.push (make_pair (edge[i].size(), i));
	}
	
	while (pq.top().first >= 2)
	{
		int left = pq.top().first, right = pq.top().second;
		if (deg[right] != left)
		{
			pq.pop();
			continue;
		}
		
		res[right] = !res[right];
		for (int i = 0; i < edge[right].size(); i++)
			fix (edge[right][i]);
		fix(right);
	}
	
	for (int i = 0; i < N; i++)
	{
		if (res[i]) cout << 1;
		else cout << 0;
	}
	cout << "\n";
	return 0;
}