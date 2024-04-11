#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 100100;

int N;
vector <int> edge[MAXN];
int dist[MAXN];

void flood (int cur, int cdist)
{
	if (dist[cur] != -1) return;
	dist[cur] = cdist;
	
	for (int i = 0; i < edge[cur].size(); i++)
		flood (edge[cur][i], cdist + 1);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		edge[x].push_back (y);
		edge[y].push_back (x);
	}
	
	for (int i = 0; i < MAXN; i++)
		dist[i] = -1;
	
	flood (0, 0);
	
	double ans = 0.0;
	for (int i = 0; i < N; i++)
		ans += 1.0 / (dist[i] + 1.0);
	cout << fixed << setprecision(7);
	cout << ans << "\n";
	return 0;
}