#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXP = (1 << 21) + 10;
const int MAXN = 500100;

int N, Q;
vector <int> edge[MAXN];
int parent[MAXN];
vector <int> child[MAXN];

int sz[MAXN];

int nord;
int ord[MAXN]; // euler order, heavy-light
int oloc[MAXN]; // location in ord
int hgood[MAXN]; // furthest up possible before not heavy

int P;
int seg[MAXP]; // 0 = all empty, 1 = all filled, 2 = mixed

inline bool cmp (int lval, int rval)
{
	return sz[lval] > sz[rval];
}

void flood (int cloc, int last)
{
	parent[cloc] = last;
	sz[cloc] = 1;
	
	for (int i = 0; i < edge[cloc].size(); i++)
		if (edge[cloc][i] != last)
			child[cloc].push_back (edge[cloc][i]);
	
	for (int i = 0; i < child[cloc].size(); i++)
	{
		flood (child[cloc][i], cloc);
		sz[cloc] += sz[child[cloc][i]];
	}
}

void flood2 (int cloc)
{
	ord[nord] = cloc;
	oloc[cloc] = nord;
	nord++;
	
	for (int i = 0; i < child[cloc].size(); i++)
	{
		int neigh = child[cloc][i];
		if (i == 0)
			hgood[neigh] = hgood[cloc];
		else
			hgood[neigh] = neigh;
		flood2 (neigh);
	}
}

inline void prop (int cloc)
{
	if (seg[cloc] != 2)
		seg[cloc*2] = seg[cloc*2+1] = seg[cloc];
}

int cstart, cend, cnum;

void fill (int cnode, int rstart, int rend)
{
	//cout << cnode << " " << rstart << " " << rend << " " << cstart << " " << cend << " " << cnum << "\n";
	
	if (rstart > cend || cstart > rend)
		return;
	
	if (rstart >= cstart && rend <= cend)
	{
		seg[cnode] = cnum;
		return;
	}
	
	prop (cnode);
	//cout << cnode << "\n";
	seg[cnode] = 2;
	
	int rmid = (rstart + rend) / 2;
	fill (cnode * 2, rstart, rmid);
	fill (cnode * 2 + 1, rmid + 1, rend);
}

int find (int cnode, int rstart, int rend, int goal)
{
	//cout << cnode << " " << rstart << " " << rend << " " << goal << "\n";
	
	if (rstart == goal && rend == goal)
		return seg[cnode];
	prop (cnode);
	int rmid = (rstart + rend) / 2;
	if (goal <= rmid)
		return find (cnode * 2, rstart, rmid, goal);
	else
		return find (cnode * 2 + 1, rmid + 1, rend, goal);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int left, right;
		cin >> left >> right;
		left--, right--;
		
		edge[left].push_back (right);
		edge[right].push_back (left);
	}
	
	flood (0, -1);
	
	for (int i = 0; i < N; i++)
		if (child[i].size() > 1)
			sort (child[i].begin(), child[i].end(), cmp);
	
	nord = 0;
	hgood[0] = 0;
	flood2 (0);
	
	P = 1;
	while (P <= N)
		P *= 2;
	for (int i = 0; i < MAXP; i++)
		seg[i] = 0;
	
	
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int op, v;
		cin >> op >> v;
		v--;
		
		if (op == 1)
		{
			cstart = oloc[v];
			cend = oloc[v] + sz[v] - 1;
			cnum = 1;
			fill (1, 0, P - 1);
		}
		else if (op == 2)
		{
			int cval = v;
			
			while (cval >= 0)
			{
				int hi = hgood[cval];
				cstart = oloc[hi];
				cend = oloc[cval];
				cnum = 0;
				fill (1, 0, P - 1);
				cval = parent[hi];
			}
		}
		else
		{
			cout << find (1, 0, P - 1, oloc[v]) << "\n";
		}
		
		/*for (int j = 1; j < 2 * P; j++)
			cout << seg[j] << " ";
		cout << "\n";*/
	}
	
	return 0;
}