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

const int nmax = 2200;

int n;

int root;
int l[nmax], r[nmax], par[nmax];
int leaf[nmax];

int cnt[nmax];
int used[nmax];
vector<int> alive;

int ask(int a, int b, int c) {
	printf("%d %d %d\n", a + 1, b + 1, c + 1);
	fflush(stdout);
	string res;
	cin >> res;
	if (res == "-1")
		exit(0);
	if (res == "X")
		return 0;
	if (res == "Y")
		return 1;
	if (res == "Z")
		return 2;
	cerr << res << endl;
	exit(1);
}

void dfs(int v) {
	alive.push_back(v);
	cnt[v] = 1;
	if (l[v] != -1 && !used[l[v]]) {
		dfs(l[v]);
		cnt[v] += cnt[l[v]];
	}
	if (r[v] != -1 && !used[r[v]]) {
		dfs(r[v]);
		cnt[v] += cnt[r[v]];
	}
}

void solve(int v, int np) {
	memset(used, 0, sizeof used);
	for (int i = 0; i < 2 * n; i ++) {
		// l[i] = l[i];
		// r[i] = r[i];
		used[i] = 0;
	}
	int cur_root = root;
	while(1) {
		if ((l[cur_root] == -1 && r[cur_root] == -1) || (used[l[cur_root]] && used[r[cur_root]])) {
			// cerr << "Inserting on top of " << cur_root << endl;
			int w = par[cur_root];

			l[np] = cur_root;
			r[np] = v;
			leaf[v] = v;
			par[cur_root] = par[v] = np;
			leaf[np] = v;

			if (w != -1) {
				if (r[w] == cur_root)
					swap(l[w], r[w]);
				l[w] = np;
				par[np] = w;
			} else {
				par[np] = -1;
				root = np;
			}
			break;
		}
		alive.clear();
		dfs(cur_root);
		int best = alive.size();
		int q = alive[0];
		for (int j = 0; j < alive.size(); j++) {
			if (l[alive[j]] == -1)
				continue;
			int now = (int)alive.size() - cnt[alive[j]];
			if (l[alive[j]] != -1)
				now = max(now, cnt[l[alive[j]]]);
			if (r[alive[j]] != -1)
				now = max(now, cnt[r[alive[j]]]);
			if (now < best) {
				best = now;
				q = alive[j];
			}
		}
		// cout << alive.size() << " " << cur_root << endl;
		// cout << q << " " << l[q] << " " << r[q] << " " << leaf[l[q]] << " " << leaf[r[q]] << endl;

		int temp = ask(leaf[l[q]], leaf[r[q]], v);
		if (temp == 0) {
			used[l[q]] = 1;
			used[r[q]] = 1;
		} else if (temp == 1) {
			cur_root = r[q];
		} else
			cur_root = l[q];
	}
}

int main ()
{
	//  freopen("input.txt", "rt", stdin);
	//  freopen("output.txt", "wt", stdout);
	cin >> n;

	int now = n + 1;
	for (int i = 0; i < n * 2; i ++)
		l[i] = r[i] = -1;

	l[n] = 0;
	r[n] = 1;
	par[0] = par[1] = n;
	par[n] = -1;
	leaf[0] = 0;
	leaf[1] = 1;
	leaf[n] = 0;

	root = n;

	for (int i = 2; i < n; i ++) {
		solve(i, now);
		now ++;
	}

	cout << -1 << endl;
	for (int i = 0; i < now; i ++)
		if (par[i] == -1)
			cout << -1 << " ";
		else
			cout << par[i] + 1 << " " ;
	cout << endl;
	fflush(stdout);


	return 0;
}