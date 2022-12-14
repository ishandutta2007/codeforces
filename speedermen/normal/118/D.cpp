#pragma comment(linker, "/STACK:100000000")
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define ppb pop_back
#define fs first
#define sd second

#define nmax 30
#define mmax 200010
#define inf 100000000

int d[111][111][2];
int n, m, a, b;

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	d[0][0][0] = d[0][0][1] = 1;
	cin >> n >> m >> a >> b;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
		{
			for(int k = 1; k <= a; ++k)
				d[i + k][j][0] = (d[i + k][j][0] + d[i][j][1]) % inf;
			for(int k = 1; k <= b; ++k)
				d[i][j + k][1] = (d[i][j + k][1] + d[i][j][0]) % inf;
		}
	cout << (d[n][m][0] + d[n][m][1]) % inf << endl;
	//while(1);
}