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
const int MAXK = 20;

int N, M;
ll x[MAXN], y[MAXN];
int next[MAXN];
int dep[MAXN];
vector <int> prev[MAXN];

int anc[MAXN][MAXK];

int hull[MAXN];
int nhull;

bool bad (int a, int b, int c) // B below AC
{
	ll x1 = x[a], x2 = x[b], x3 = x[c];
	ll y1 = y[a], y2 = y[b], y3 = y[c];
	return (x2 - x1) * y3 + (x3 - x2) * y1 > (x3 - x1) * y2;
}

void flood (int cloc, int cdep)
{
	dep[cloc] = cdep;
	for (int i = 0; i < prev[cloc].size(); i++)
		flood (prev[cloc][i], cdep + 1);
}

int aval (int a, int nval)
{
	for (int i = 0; i < MAXK; i++)
		if (nval & (1 << i))
			a = anc[a][i];
	return a;
}

int main()
{
	ios_base::sync_with_stdio (0);
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];
	
	nhull = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		while (nhull >= 2 && bad (i, hull[nhull - 1], hull[nhull - 2]))
			nhull--;
		
		
		hull[nhull++] = i;
		if (i < N - 1)
			next[i] = hull[nhull-2];
	}
	next[N-1] = N - 1;
	
	for (int i = 0; i < N - 1; i++)
		prev[next[i]].push_back (i);
	
	flood (N - 1, 0);
	
	for (int i = 0; i < N; i++)
		anc[i][0] = next[i];
	for (int i = 1; i < MAXK - 1; i++)
	{
		for (int j = 0; j < N; j++)
			anc[j][i] = anc[anc[j][i-1]][i-1];
	}
	
	//for (int i = 0; i < N; i++)
	//	cout << next[i] << "\n";
		
	
	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		
		if (dep[a] < dep[b])
			swap (a, b);
		
		//cout << a << " " << b << "\n";
		
		a = aval (a, dep[a] - dep[b]);
		
		//cout << a << " " << b << "\n";
		
		if (i) cout << " ";
		if (a == b)
			cout << a + 1;
		else
		{
			for (int j = MAXK - 1; j >= 0; j--)
				if (anc[a][j] != anc[b][j])
				{
					a = anc[a][j];
					b = anc[b][j];
				}
			a = next[a];
			cout << a + 1;
		}
	}
	
	cout << "\n";
	
	return 0;
}