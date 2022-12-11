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
const int kmax = 6;

int n, k;
vector<int> g[nmax];
long long cnt[nmax][kmax], sumLen[nmax][kmax];
long long res;
int used[nmax];

void solve(int v, int p) {
	used[v] = 1;
	sumLen[v][0] = 0;
	cnt[v][0] = 1;
	for (int i = 0; i < g[v].size(); i ++)
		if (g[v][i] != p) {
			int u = g[v][i];
			solve(u, v);
			for (int j = 0; j < k; j ++)
				for (int e = 0; e < k; e ++) {
					res += sumLen[u][j] * cnt[v][e];
					res += sumLen[v][e] * cnt[u][j];
					if (e + j + 1 > 0)
						res += cnt[u][j] * cnt[v][e];
					if (e + j + 1 > k)
						res += cnt[u][j] * cnt[v][e];
				}

			for (int j = 0; j < k - 1; j ++) {
				sumLen[v][j+1] += sumLen[u][j];
				cnt[v][j+1] += cnt[u][j];
			}
			sumLen[v][0] += sumLen[u][k-1] + cnt[u][k-1];
			cnt[v][0] += cnt[u][k-1];
		}
	// cout << v << " " << res << endl;
	// for (int e = 0; e < k; e ++)
	// 	cout << cnt[v][e] << " ";
	// cout << endl;
	// for (int e = 0; e < k; e ++)
	// 	cout << sumLen[v][e] << " ";
	// cout << endl;
	// cout << endl;
}

int main ()
{
	//  freopen("input.txt", "rt", stdin);
	//  freopen("output.txt", "wt", stdout);
	cin >> n >> k;
	for (int i = 0; i < n - 1; i ++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a --; b --;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	solve(0, -1);
	cout << res << endl;

	return 0;
}