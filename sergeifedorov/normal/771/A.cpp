#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 200200;

int n, m;
vector<int> g[nmax];
long long V, E;
int used[nmax];

void no() {
	puts("NO");
	exit(0);
}

void dfs(int v) {
	used[v] = 1;
	V ++;
	E += g[v].size();
	for (int i = 0; i < g[v].size(); i ++)
		if (!used[g[v][i]])
			dfs(g[v][i]);
}

void yes() {
	puts("YES");
	exit(0);
}

int main ()
{
	//  freopen("input.txt", "rt", stdin);
	//  freopen("output.txt", "wt", stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a --;
		b --;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(used, 0, sizeof used);
	for (int i = 0; i < n; i ++)
		if (!used[i]) {
			V = 0;
			E = 0;
			dfs(i);
			// cout << i << " " << V << " " << E << endl;
			if (E != V * (V - 1)) no();
		}
	yes();


	return 0;
}