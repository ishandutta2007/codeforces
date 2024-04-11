#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
const ll MAXN = 100100;
const int MAXM = 1000100;

int N, M;

vector <int> edge[MAXM];
map <ll, int> cmap;
set <int> myset;

int res[MAXM];
bool found;

inline bool ex (int a, int b)
{
	return cmap.find (a*MAXN+b) != cmap.end();
}

void solve (int dep)
{
	if (found) return;
	
	if (dep == M + 1)
	{
		found = true;
		return;
	}
	if (dep == N)
	{
		if (!ex (res[0], res[N-1]))
			found = true;
		return;
	}
	
	int cval = res[dep-1];
	
	for (set <int>::iterator it = myset.begin(); it != myset.end(); it++)
	{
		int x = *it;
		
		if (!ex (x, cval))
		{
			res[dep] = x;
			myset.erase (it);
			
			solve (dep + 1);
			
			if (found) return;
			
			myset.insert (x);
			it = myset.find (x);
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		start--, end--;
		edge[start].push_back (end);
		edge[end].push_back (start);
		
		cmap[MAXN*start+end] = 1;
		cmap[MAXN*end+start] = 1;
	}
	
	found = false;
	if (N <= 10)
	{
		for (int i = 0; i < N; i++)
			res[i] = i;
		
		do
		{
			bool good = true;
			for (int i = 0; i < min (M, N - 1); i++)
				if (ex (res[i], res[i+1]))
					good = false;
			
			if (M == N)
				if (ex (res[0], res[N-1]))
					good = false;
			
			if (good)
			{
				found = true;
				for (int i = 0; i < min (M, N - 1); i++)
					cout << res[i] + 1 << " " << res[i+1] + 1 << "\n";
				if (M == N)
					cout << res[0] + 1 << " " << res[N-1] + 1 << "\n";
				break;
			}
		} while (next_permutation (res, res + N));
		
		if (!found)
			cout << -1 << "\n";
		return 0;
	}
	
	for (int i = 1; i < N; i++)
		myset.insert (i);
	res[0] = 0;
	
	solve (1);
	
	for (int i = 0; i < min (M, N - 1); i++)
		cout << res[i] + 1 << " " << res[i+1] + 1 << "\n";
	if (M == N)
		cout << res[0] + 1 << " " << res[N-1] + 1 << "\n";
	return 0;
}