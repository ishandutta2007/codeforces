#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 300100;
const int MAXP = (1 << 21) + 100;

int N, Q;
int P;
int arr[MAXN];
int loc[MAXN];

int seg[MAXP];

void upd (int cloc, int nval)
{
	cloc += P;
	int diff = nval - seg[cloc];
	
	while (cloc)
	{
		seg[cloc] += diff;
		cloc /= 2;
	}
}

int qsum (int val)
{
	int cbit = P / 2, res = 0;
	int cloc = 1;
	while (cbit)
	{
		if (val & cbit)
		{
			res += seg[2*cloc];
			cloc = 2 * cloc + 1;
		}
		else
			cloc = 2 * cloc;
		cbit /= 2;
	}
	return res;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		arr[i]--;
		loc[arr[i]] = i;
	}
	
	P = 1;
	while (P <= N)
		P *= 2;
	for (int i = 0; i < MAXP; i++)
		seg[i] = 0;
	
	for (int i = 0; i < N - 1; i++)
		if (loc[i] > loc[i+1])
			upd (i, 1);
	
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int a, x, y;
		cin >> a >> x >> y;
		x--, y--;
		
		if (a == 1)
		{
			cout << qsum (y) - qsum (x) + 1 << "\n";
		}
		else
		{
			int nx = arr[x], ny = arr[y];
			
			swap (arr[x], arr[y]);
			swap (loc[nx], loc[ny]);
			
			if (nx > 0)
				upd (nx - 1, loc[nx-1] > loc[nx]);
			if (nx < N)
				upd (nx, loc[nx] > loc[nx+1]);
			if (ny > 0)
				upd (ny - 1, loc[ny-1] > loc[ny]);
			if (ny < N)
				upd (ny, loc[ny] > loc[ny+1]);
		}
	}
	
	return 0;
}