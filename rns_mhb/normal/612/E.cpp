#include <bits/stdc++.h>
using namespace std;

#define N 1010101

int a[N], n, b[N];
bool vis[N];

vector <int> v[N];

bool cmp(vector <int> v, vector <int> u) {
	return v.size() < u.size();
}

void create(vector <int> &v) {
	int sz = v.size();
	for (int i = 0; i < sz; i ++) b[v[i]] = v[(i+(sz>>1)+1)%sz];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

	int e = 0;
	for (int i = 1; i <= n; i ++) if (!vis[i]) {
		e ++;
		v[e].push_back(i);
		for (int j = a[i]; j != i; j = a[j]) v[e].push_back(j);
		for (int i = 0; i < v[e].size(); i ++) vis[v[e][i]] = 1;
	}
	sort(v + 1, v + e + 1, cmp);
	for (int i = 1; i <= e; i ++) {
		int sz = v[i].size();
		if (sz & 1) create(v[i]);
		else {
			if (i == e || ((int)(v[i+1].size()) != sz)) {
				puts("-1");
				return 0;
			}
			for (int j = 0; j < sz; j ++) b[v[i][j]] = v[i+1][j];
			for (int j = 0; j < sz; j ++) b[v[i+1][j]] = v[i][(j+1)%sz];
			i ++;
		}
	}
	for (int i = 1; i <= n; i ++) printf("%d%c", b[i], i == n ? '\n' : ' ');


	return 0;
}