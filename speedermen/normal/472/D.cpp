#pragma comment(linker, "/STACK:100000000")
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <string>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef complex < double > cd;
 
const bool db = false;
 
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define sd second
#define fs first
 
#define inf 1000000007
#define nmax 100010
#define mmax 100010
#define eps 1e-9

int n, g[2010][2010];
ll dd[2010], pr[2010];
bool mark[2010];
bool D[2010][2010];
int p[2010];
queue < int > q;
vector < pair < int, int > > G[2010];
pair < int, pair < int, int > > V[2010 * 2010];

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
	scanf("%d", &n);
	bool ok = true;
	int ptr = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &g[i][j]);
			if(i == j)
				ok &= g[i][j] == 0;
		}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(i != j) {
				ok &= g[i][j] == g[j][i];
				ok &= g[i][j] != 0;
				V[ptr++] = mp(g[i][j], mp(i, j));
			}
	for(int i = 1; i <= n; ++i)
		p[i] = i;
	sort(V, V + ptr);
	int u = 0, v = 0, cnt = 0;
	for(int i = 0; i < ptr; ++i) {
		int a = V[i].sd.fs, b = V[i].sd.sd, c = V[i].fs;
		if(get(a) != get(b)) {
			G[a].pb(mp(b, c));
			G[b].pb(mp(a, c));
			a = get(a); b = get(b);
			++cnt;
			if(a & 1)
				swap(a, b);
			p[a] = b;
		}
	}
	ok &= cnt == n - 1;
	for(int i = 1; i <= n && ok; ++i) {
		for(int j = 1; j <= n; ++j)
			dd[j] = inf;
		dd[i] = 0;
		set < pair < int, int > > s;
		s.insert(mp(0, i));
		while(!s.empty()) {
			int v = s.begin()->sd; s.erase(s.begin());
			for(int j = 0; j < G[v].size(); ++j) {
				int to = G[v][j].fs, len = G[v][j].sd;
				if(dd[to] > dd[v] + len) {
					s.erase(mp(dd[to], to));
					dd[to] = dd[v] + len;
					s.insert(mp(dd[to], to));
				}
			}
		}
		for(int j = 1; j <= n; ++j)
			if(dd[j] != g[i][j])
				ok = false;
	}
	cout << (ok ? "YES" : "NO") << endl;
	cin.get(); cin.get();
	return 0;
}