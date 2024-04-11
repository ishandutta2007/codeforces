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

#define N 100010
int n, m;
int v[N];

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> v[i];
	ll S = 0;
	while (m--) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		S += min(v[x],v[y]);
	}
	cout << S << endl;
	return 0; 
}