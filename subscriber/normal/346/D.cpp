#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<sstream>
#define SS stringstream
#define pw(x) (1ll << (x))
#define m0(x) memset(x, 0, sizeof(x))
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, a, b;
int d[1000111];
vector<int> di[1000111];
vector<pair<int,int> > v[1000111];

int h[1000111], worst[1000111];

int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		di[x].pb(y);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < di[i].size(); j++) {
			int s = 1;
			if (di[i].size() == 1) s = 0;
//			cout << di[i][j] << " " << i << " " << s << endl;
			v[di[i][j]].pb(mp(i, s));
		}
	}
	for (int i = 0; i < n; i++) worst[i] = -1;


	deque<int> Q;
	int a, b;
	cin >> a >> b;
	a--;
	b--;
	for (int i = 0; i < n; i++) d[i] = 1e9;
	d[b] = 0;
	Q.push_back(b);
	while (Q.size()) {
		int x = Q.front();
		Q.pop_front();
		for (int i = 0; i < v[x].size(); i++) {
			int to = v[x][i].F;
			h[to]++;
			worst[to] = max(worst[to], d[x]);

			int val = d[x] + v[x][i].S;
			if (h[to] == di[to].size()) val = min(val, worst[to]);

			if (val >= d[to]) continue;

			d[to] = val;

			if (val > d[x]) Q.push_back(to); else Q.push_front(to);

		}
	}
	if (d[a] == 1e9) d[a]= -1;
	cout << d[a] << endl;
	return 0;
}