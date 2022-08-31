#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 26;

int N;
int C[MAXN];
int ccount[MAXN];
bool found;
int start;

void run (int);

void rrun (int sum, int hval, int cloc)
{
	if (clock() - start > .8 * CLOCKS_PER_SEC)
		return;
	if (sum == 0)
		run (cloc + 1);
	if (hval == 0)
		return;
	
	if (ccount[hval])
	{
		ccount[hval]--;
		rrun (sum - hval, hval, cloc);
		ccount[hval]++;
	}
	rrun (sum, hval - 1, cloc);
}

void run (int cloc)
{
	if (clock() - start > .8 * CLOCKS_PER_SEC)
		return;
	if (cloc == N)
	{
		for (int i = 1; i < N; i++)
			if (ccount[i])
				return;
		found = true;
	}
	if (found) return;
	
	if (C[cloc] == 1)
	{
		ccount[1]++;
		run (cloc + 1);
	}
	else
	{
		ccount[C[cloc]]++;
		rrun (C[cloc] - 1, C[cloc] - 2, cloc);
	}
}

int main()
{
	start = clock();
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> C[i];
	sort (C, C + N);
	
	found = false;
	run (0);
	
	if (found) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}