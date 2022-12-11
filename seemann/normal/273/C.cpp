#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;
const int MAXN = 3 * 1e5 + 10;

vector<int> e[MAXN];
int c[MAXN];
int p[MAXN];

void add(int v, int col) {
	int cur = -1;
	c[v] = col;
	FOR(i, e[v].size()) {
		if (col == c[e[v][i]]){
			cur = e[v][i];
			break;
		}
	}
	if (cur == -1) {
		p[v] = -1;
		return;
	}
	if (p[cur] == -1) {
		p[cur] = v;
		p[v] = cur;
		return;
	}
	p[v] = -1;
	p[p[cur]] = -1;
	add(cur, 1 - col);
}

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n, m;
	cin >> n >> m;
	FOR(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	FOR(i, n) {
		c[i] = -1;
		p[i] = -1;
	}
	FOR(i, n) {
		int cnt[2];
		cnt[0] = 0;
		cnt[1] = 0;
		FOR(j, e[i].size()) {
			if (c[e[i][j]] != -1)
				cnt[c[e[i][j]]]++;
		}
		if (cnt[1] > cnt[0])
			add(i, 0);
		else
			add(i, 1);
	}
	FOR(i, n)
		printf("%d", c[i]);

	return 0;
}