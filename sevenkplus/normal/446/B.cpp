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

typedef long long ll;
typedef pair<ll,int> PLI;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 1010
int n, m, k, p;
ll r[N], c[N];
set<PLI> R, C;
ll wR[N*N], wC[N*N];

int main()
{
	cin >> n >> m >> k >> p;
	for (int i = 0; i < n; i ++) 
		for (int j = 0; j < m; j ++) {
			int x; cin >> x;
			r[i] += x;
			c[j] += x;
		}
	for (int i = 0; i < n; i ++)
		R.insert(mp(-r[i],i));
	for (int i = 0; i < m; i ++)
		C.insert(mp(-c[i],i));
	for (int i = 1; i <= k; i ++) {
		PLI w = *R.begin();
		wR[i] = wR[i-1]-w.fi;
		R.erase(w);
		w.fi += p*m;
		R.insert(w);
	}
	for (int i = 1; i <= k; i ++) {
		PLI w = *C.begin();
		wC[i] = wC[i-1]-w.fi;
		C.erase(w);
		w.fi += p*n;
		C.insert(w);
	}
	ll S = -1e18;
	for (int i = 0; i <= k; i ++) 
		S = max(S,wR[i]+wC[k-i]-(ll)p*i*(k-i));
	cout << S << endl;
	return 0;
}