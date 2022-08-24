#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 110;

int N;
int rval[MAXN];
int cval[MAXN];

int main()
{
	for (int i = 0; i < MAXN; i++)
		rval[i] = cval[i] = -1;
	
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			char ch; cin >> ch;
			if (ch == '.')
			{
				rval[i] = j;
				cval[j] = i;
			}
		}
	
	bool rgood = true, cgood = true;
	for (int i = 0; i < N; i++)
	{
		if (rval[i] == -1)
			rgood = false;
		if (cval[i] == -1)
			cgood = false;
	}
	
	if (rgood || cgood)
	{
		if (rgood)
		{
			for (int i = 0; i < N; i++)
				cout << i + 1 << " " << rval[i] + 1 << "\n";
		}
		else
			for (int i = 0; i < N; i++)
				cout << cval[i] + 1 << " " << i + 1 << "\n";
	}
	else
		cout << "-1\n";
	return 0;
}