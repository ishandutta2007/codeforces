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

#define N 1000010
int n, a[N];
int le[N], ri[N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	a[0] = -1e9+7;
	a[n+1] = 1e9+7;
	le[0] = 0; 
	for (int i = 1; i <= n; i ++) {
		if (a[i] > a[i-1]) le[i] = le[i-1]+1;
		else le[i] = 1;
	}
	ri[n+1] = 0;
	for (int i = n; i >= 1; i --) {
		if (a[i] < a[i+1]) ri[i] = ri[i+1]+1;
		else ri[i] = 1;
	}
	int S = 0;
	for (int i = 1; i <= n; i ++) {
		S = max(S, le[i]);
		S = max(S, ri[i]);
		S = max(S, le[i-1]+1);
		S = max(S, ri[i+1]+1);
		if (a[i-1]+1 <= a[i+1]-1) S = max(S, le[i-1]+1+ri[i+1]);
	}
	cout << S << endl;
	return 0;
}