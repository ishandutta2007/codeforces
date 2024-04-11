#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
const int MAXN = 110;

int N, D;
int a[MAXN];
int x[MAXN], y[MAXN];
int edge[MAXN][MAXN];

int dist[MAXN];
bool seen[MAXN];

int main()
{
	cin >> N >> D;
	
	for (int i = 1; i < N - 1; i++)
		cin >> a[i];
	a[0] = a[N-1] = 0;
	
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			edge[i][j] = D * (abs (x[i] - x[j]) + abs (y[i] - y[j]));
		}
	
	for (int i = 0; i < N; i++)
	{
		dist[i] = 1e9;
		seen[i] = false;
	}
	
	seen[0] = true;
	dist[0] = 0;
	
	for (int i = 1; i < N; i++)
		dist[i] = edge[0][i] - a[i];
	
	for (int i = 0; i < N - 1; i++)
	{
		int lo = 1e9, loc = -1;
		for (int j = 0; j < N; j++)
			if (!seen[j] && dist[j] < lo)
			{
				lo = dist[j];
				loc = j;
			}
		
		seen[loc] = true;
		
		for (int j = 0; j < N; j++)
			if (!seen[j])
				dist[j] = min (dist[j], dist[loc] + edge[loc][j] - a[j]);
	}
	
	cout << dist[N-1] << "\n";
	return 0;
}