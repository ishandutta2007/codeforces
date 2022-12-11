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

const int nmax = 110000;

int n, k;
vector<int> g[nmax];
int used[nmax];
int st[nmax];
vector<int> res;

void no() {
	cout << -1 << endl;
	exit(0);
}

void dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		if (used[g[v][i]] == 1) no();
		if (!used[g[v][i]]) dfs(g[v][i]);
	}
	res.push_back(v + 1);
	used[v] = 2;
}

int main ()
{
	//  freopen("input.txt", "rt", stdin);
	//  freopen("output.txt", "wt", stdout);
	
	cin >> n >> k;
	for (int i = 0; i < k; i ++) {
		scanf("%d", &st[i]);
		st[i] --;
	}	

	for (int i = 0; i < n; i ++) {
		int e;
		scanf("%d", &e);
		g[i].resize(e);
		for (int j = 0; j < e; j ++) {
			scanf("%d", &g[i][j]);
			g[i][j] --;
		}
	}
	memset(used, 0, sizeof used);
	for (int i = 0; i < k; i ++)
		if (!used[st[i]])
			dfs(st[i]);
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
		printf("%d ", res[i]);
	printf("\n");
	return 0;
}