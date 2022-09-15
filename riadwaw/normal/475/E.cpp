/**
 * BE CAREFUL!! I have define int li sometimes
 */

//#define _GLIBCXX_DEBUG

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <bitset>
#include <map>
#include <cassert>
#include <memory.h>
#include <limits>
#include <numeric>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void solve();

void prec();


#define FILENAME "souvenir"

int main() {
	string s = FILENAME;
#ifdef DEBUG
	freopen("/Users/RiaD/Contests/Contests/input", "r", stdin);
	//freopen("/Users/RiaD/Contests/Contests/output", "w", stdout);
	//cout<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
	cout.sync_with_stdio(0);
	cout.precision(20);
	cout << fixed;
	//prec();
	int tests = 1;
	//cin >> tests;

	while (tests--) {
		solve();
	}
#ifdef DEBUG
	//cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}

const int MAXN = 2202;
int n;
vector<int> g[MAXN];
bool used[MAXN];

char matrix[MAXN][MAXN];
int timer, tin[MAXN], fup[MAXN];

vector<pi> bridges;



void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (size_t to=0; to< n; ++to) {
		if(matrix[v][to] == 0) {
			continue;
		}
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v]) {

				bridges.push_back(pi(v, to));
				matrix[v][to] = 0;
				matrix[to][v] = 0;
			}
		}
	}
}

void find_bridges() {
	timer = 0;
	for (int i=0; i<n; ++i)
		used[i] = false;
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs (i);
}

int dsu[MAXN];
int size[MAXN];

int get(int a) {
	if(dsu[a] == a)
		return a;
	else
		return dsu[a] = get(dsu[a]);
}

void unite(int a, int b) {
	a = get(a);
	b = get(b);
	if(a == b)
		return;
	dsu[a] = b;
	size[b] += size[a];
	size[a] = 0;

}

int xxx[MAXN];

int go(int v, int p) {

	int res = size[v];

		for(int to:g[v])
			if(to != p)
				res += go(to, v);
	xxx[v] = res;
	return res;
}

int go2(int v, int p) {
	//int res = size[v];
	int res = size[v] * size[v];

	for(int to:g[v])
		if(to != p) {
			res += go2(to, v);

			res += xxx[to] * size[v];
		}
	return res;
}
void solve( ) {
	int m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		--a, --b;
		matrix[a][b] = matrix[b][a] = 1;
	}



	find_bridges();
	for(int i = 0; i < n; ++i) {
		dsu[i] = i;
		size[i] = 1;
	}


	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			if(matrix[i][j]) {
				unite(i, j);
			}
	}


	for(auto x: bridges) {
		int a = get(x.first);
		int b = get(x.second);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int res = 0;
	for(int root = 0; root < n; ++root)
	{
		if(size[root] == 0)
			continue;

		int ans = 0;

		//ans += size[root] * (size[root] - 1) / 2;


		ans += size[root] * n;


		vi sizes;
		for(int to: g[root]) {
			int z = go(to, root);
			sizes.push_back(z);
			int t = go2(to, root);
			//cout << root << ' ' << to << ' ' <<t << "\n";
			ans += t;
		}

		///cout << ans << "\n";


		vector<int> pos(n + 1);


		pos[0] = true;

		for(int size: sizes) {
		for(int i = n - 1; i >= 0; --i) {
			if(!pos[i])
				continue;

				if(i + size <= n) {
					pos[i + size] = true;
				}
			}

		}

		int mx = 0;
		for(int k = 0; k <= n; ++k) {
			if(pos[k]) {
				mx = max(mx, k * (n - size[root] - k));
			}
		}

		res = max(ans + mx, res);
	}


	cout << res;



}