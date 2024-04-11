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
const int MAXN = 200100;
const ll MANS = 1e11;

int N, M;
ll head[MAXN];
ll track[MAXN];

bool good (ll xval, ll lval, ll rval, ll x)
{
	if (lval >= xval)
		return rval - xval <= x;
	if (rval <= xval)
		return xval - lval <= x;
	return min (2 * (xval - lval) + (rval - xval), 2 * (rval - xval) + (xval - lval)) <= x;
}

bool works (ll x)
{
	int ctrack = 0;
	
	for (int i = 0; i < N; i++)
	{
		ll cdist = abs (track[ctrack] - head[i]);
		
		if (cdist > x) continue;
		
		int lo = ctrack, hi = M - 1;
		while (lo < hi)
		{
			int mid = (lo + hi + 1) / 2;
			
			if (good (head[i], track[ctrack], track[mid], x))
				lo = mid;
			else
				hi = mid - 1;
		}
		
		ctrack = lo + 1;
		if (ctrack == M) return true;
	}
	return (ctrack == M);
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> head[i];
	for (int i = 0; i < M; i++)
		cin >> track[i];
	
	ll lo = 0, hi = MANS;
	
	while (lo < hi)
	{
		ll mid = (lo + hi) / 2;
		if (works (mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	
	cout << lo << "\n";
	return 0;
}