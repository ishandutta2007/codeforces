#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const int P = (1 << 18);
const int MAXP = (1 << 20) + 100;

int N, M;
int arr[MAXN];

vector <int> edge[MAXN];
int dep[MAXN];
int ssize[MAXN];

int ntour;
int tour[MAXN];
int tloc[MAXN];

int seg[MAXP];

void flood (int cloc, int cdep, int last)
{
	dep[cloc] = cdep;
	tour[ntour] = cloc;
	tloc[cloc] = ntour;
	ntour++;
	
	ssize[cloc] = 1;
	for (int i = 0; i < edge[cloc].size(); i++)
	{
		int neigh = edge[cloc][i];
		if (neigh == last) continue;
		
		flood (neigh, cdep + 1, cloc);
		ssize[cloc] += ssize[neigh];
	}
}

void add (int cloc, int v)
{
	cloc += P;
	while (cloc)
	{
		seg[cloc] += v;
		cloc /= 2;
	}
}

int find (int cloc)
{
	cloc += P;
	
	int res = 0;
	while (cloc > 1)
	{
		if (cloc % 2)
			res += seg[cloc-1];
		cloc /= 2;
	}
	return res;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		
		edge[u].push_back (v);
		edge[v].push_back (u);
	}
	
	ntour = 0;
	flood (0, 0, -1);
	
	for (int i = 0; i < MAXP; i++)
		seg[i] = 0;
	for (int i = 0; i < N; i++)
	{
		seg[tloc[i]+P] = arr[i];
		if (dep[i] % 2)
			seg[tloc[i]+P] *= -1;
	}
	
	
	for (int i = P + N - 1; i > P; i--)
		seg[i] -= seg[i-1];
	
	for (int i = P - 1; i >= 1; i--)
		seg[i] = seg[2*i] + seg[2*i+1];
	
	//for (int i = 0; i < N; i++)
	//	cout << tloc[i] << "\n";
	
	for (int i = 0; i < M; i++)
	{
		/*for (int j = 0; j < N; j++)
			cout << j << " " << find (tloc[j] + 1) * ((dep[j] % 2) ? -1 : 1) << "\n";
		cout << "\n";*/
		
		int t;
		cin >> t;
		
		if (t == 1)
		{
			int x, val;
			cin >> x >> val;
			
			x--;
			if (dep[x] % 2)
				val = -val;
			
			int start = tloc[x], end = tloc[x] + ssize[x];
			add (start, val);
			add (end, -val);
		}
		else
		{
			int x;
			cin >> x;
			
			x--;
			
			cout << find (tloc[x] + 1) * ((dep[x] % 2) ? -1 : 1) << "\n";
		}
	}
	
	return 0;
}