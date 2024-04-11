#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, m, q, o, a, b, f[N];
bool on[N];
vector <int> v[N];

void add(int a, int b) {
	if (v[a].size() > v[b].size()) swap(a, b);
	v[a].push_back(b);
	f[b] += on[a];
}

void online(int a) {
	on[a] = 1;
	for (int i = 0; i < v[a].size(); i ++) f[v[a][i]] ++;
}

void offline(int a) {
	on[a] = 0;
	for (int i = 0; i < v[a].size(); i ++) f[v[a][i]] --;
}

void del(int a, int b) {
	bool ab = 0;
	for (int i = 0; i < v[a].size(); i ++) {
		if (v[a][i] == b) {
			ab = 1;
			v[a].erase(v[a].begin() + i); break;
		}
	}
	for (int i = 0; i < v[b].size(); i ++) {
		if (v[b][i] == a) {
			ab = 0;
			v[b].erase(v[b].begin() + i); break;
		}
	}
	if (ab) f[b] -= on[a];
	else f[a] -= on[b];
}

void query(int a) {
	int rlt = f[a];
	for (int i = 0; i < v[a].size(); i ++) rlt += on[v[a][i]];
	printf("%d\n", rlt);
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &q);
	scanf("%d", &o);
	for (int i = 1; i <= o; i ++) {
		scanf("%d", &a);
		on[a] = 1;
	}
	while (m --) {
		scanf("%d %d", &a, &b);
		add(a, b);
	}
	char oper[3];
	while (q --) {
		scanf("%s", oper);
		if (oper[0] == 'O') {
			scanf("%d", &a);
			online(a);
		}
		else if (oper[0] == 'F') {
			scanf("%d", &a);
			offline(a);
		}
		else if (oper[0] == 'A') {
			scanf("%d %d", &a, &b);
			add(a, b);
		}
		else if (oper[0] == 'D') {
			scanf("%d %d", &a, &b);
			del(a, b);
		}
		else {
			scanf("%d", &a);
			query(a);
		}
	}
	return 0;
}