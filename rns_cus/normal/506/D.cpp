//============================================================================
// Name        : 286_D.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define N 101000
int vis[N], T, a[N], b[N], c[N];
typedef pair<int,int> pi;
vector<int> v[N], V[N], col[N];
set<pi> S[N];
set<pi> :: iterator it;
vector<pi> Root[N];
int root[N];
map <pi, int> mp;
int ans[N];

int Fa(int x) {
	if(x == root[x]) return x;
	return root[x] = Fa(root[x]);
}

void doit(int id) {
	int x = a[id];
	int y = b[id];
	int co = c[id];
	if(vis[x] != T) {
		vis[x] = T;
		root[x] = x;
		V[co].push_back(x);
	}
	if(vis[y] != T) {
		vis[y] = T;
		root[y] = y;
		V[co].push_back(y);
	}
	int x1 = Fa(x);
	int y1 = Fa(y);
	if(x1 == y1) return ;
	root[x1] = y1;
	return ;
}

void Add(int co) {
	for(int i = 0; i < (int)V[co].size(); i ++) {
		int x = V[co][i];
		int z = Fa(x);
		Root[x].push_back(pi(co, z));
	}
}


int main() {
	//freopen("1.in", "r", stdin);
	int n, m, q, st, en;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) v[i].clear();
	for(int i = 0; i < m; i ++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		v[a[i]].push_back(i);
		v[b[i]].push_back(i);
		col[c[i]].push_back(i);
	}
	T = 0;
	for(int i = 1; i <= m; i ++) if(col[i].size()){
		T ++;
		for(int j = 0; j < (int)col[i].size(); j ++) {
			int k = col[i][j];
			doit(k);
		}
		Add(i);
	}
	for(int i = 1; i <= n; i ++) sort(Root[i].begin(), Root[i].end());
	scanf("%d", &q);
	mp.clear();
	for(int i = 1; i <= q; i ++) {
		scanf("%d%d", &st, &en);
		if(st > en) swap(st, en);
		int xx = mp[pi(st, en)];
		if(xx) printf("%d\n", ans[xx]);
		else {
			mp[pi(st, en)] = i;
			if(Root[st].size() > Root[en].size()) swap(st, en);
			for(int j = 0; j < (int)Root[st].size(); j ++) {
				pi a = Root[st][j];
				xx = lower_bound(Root[en].begin(), Root[en].end(), a) - Root[en].begin();
				int zz = Root[en].size();
				if(xx != zz) {
					pi b = Root[en][xx];
					if(a.first == b.first && a.second == b.second) ans[i] ++;
				}
			}
			printf("%d\n", ans[i]);
		}
	}
	return 0;

}