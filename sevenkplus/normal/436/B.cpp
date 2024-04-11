#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 2010
int n,m,k; string s[N];
int a[N];

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i ++) cin >> s[i];
	for (int i = 0; i < n; i ++) 
		for (int j = 0; j < m; j ++)
			if (s[i][j] == 'U') {
				if (~i&1) a[j] ++;
			} else
			if (s[i][j] == 'L') {
				if (j-i >= 0) a[j-i] ++;
			} else 
			if (s[i][j] == 'R') {
				if (j+i <= m-1) a[j+i] ++;
			}
	for (int i = 0; i < m; i ++) 
		printf ("%d%c",a[i],i==m-1?'\n':' ');
	return 0;
}