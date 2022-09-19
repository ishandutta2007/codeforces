#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 200 * 1000 + 100;

vector <int> vertex[size];
int col[size], chet[size];
int ans[size];
bool flag = true;
int dist[size];
int n, m;

void dfs(int v, int c, int ch) {
	col[v] = c;
	chet[v] = ch;

	for (int i = 0; i < (int) vertex[v].size(); i++) {
		if (col[vertex[v][i]] == -1) {
			dfs(vertex[v][i], c, ch ^ 1);
		} else {
			if (chet[vertex[v][i]] != (ch ^ 1)) {
				flag = false;
			}
		}
	}
}

void bfs(int v) {
	for (int i = 0; i < n; i++) {
		dist[i] = -1;
	}

	queue <int> q;
	q.push(v);
	dist[v] = 0;
	
	while (!q.empty()) {
		int curv = q.front();
		q.pop();

		for (int i = 0; i < (int) vertex[curv].size(); i++) {
			if (dist[vertex[curv][i]] == -1) {
				dist[vertex[curv][i]] = dist[curv] + 1;
				q.push(vertex[curv][i]);
			}
		}
	}
}

int main() {
/*
	freopen("input.txt", "w", stdout);
	int n = 1000;
	int m = 100 * 1000;

	cout << n << ' ' << m << endl;
	for (int i = 0; i < m; i++) {
		int v = rand() % (n / 2);
		int u = rand() % (n / 2) + n / 2;

		cout << v  + 1 << ' ' << u + 1 << endl;
	}

	return 0;
*/
//    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
    	int v, u;
    	scanf("%d%d", &v, &u);

    	v--, u--;

    	vertex[v].pb(u);
    	vertex[u].pb(v);
    }

    for (int i = 0; i < n; i++) {
    	col[i] = -1;
    	chet[i] = -1;
    }	

    int cmp = 0;

    for (int i = 0; i < n; i++) {
    	if (col[i] == -1)
	   		dfs(i, cmp++, 0);
    }

    if (!flag) {
    	cout << -1 << endl;
    	return 0;
    }

    for (int i = 0; i < n; i++) {
    	bfs(i);
    	int mx = 0;
    	for (int j = 0; j < n; j++)
    		mx = max(mx, dist[j]);
    	ans[col[i]] = max(ans[col[i]], mx);
    }

    int sum = 0;
    for (int i = 0; i < cmp; i++)
    	sum += ans[i];

  	cout << sum << endl;	

  	cerr << (clock() + 0.0) / CLOCKS_PER_SEC << endl;

    return 0;
}