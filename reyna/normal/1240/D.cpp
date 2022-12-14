
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
int ed[N], a[N];
int par[N], sz[N];
map<int, int> ss[N];
pair<int, int> find(int x) {
	if (x == par[x]) return mp(x, 0);
	auto f = find(par[x]);
	par[x] = f.first;
	sz[x] += f.second;
	return mp(par[x], sz[x]);
}
int main() {
	ios_base::sync_with_stdio(0);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) cin >> a[j], --a[j];
		par[n] = ed[n] = n; sz[n] = 0;
		for (int j = n - 1; j >= 0; --j) {
			ed[j] = j;
			{
				if (j + 1 < n) {
					int x = ss[find(j + 1).first][a[j]];
					if (x > 0) {
						ed[j] = x + 1;
					}
				}
				/*
				int pos = j + 1;
				while (pos < n) {
					if (a[pos] == a[j]) {
						ed[j] = pos + 1;	
						break;
					}
					if (pos == ed[pos]) break;
					pos = ed[pos];
				}
				*/
			}
			par[j] = ed[j];
			if (j != ed[j])
				sz[j] = 1;
			ss[find(j).first][a[j]] = j;
		}
		long long res = 0;
		for (int j = 0; j < n; ++j) {
			res += find(j).second;	
		}
		cout << res << '\n';
		for (int j = 0; j <= n; ++j) ss[j].clear(), par[j] = sz[j] = ed[j] = 0;
	}
		
		
}