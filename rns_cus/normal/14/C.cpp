#include <bits/stdc++.h>
using namespace std;
#define N 7

int id[N];
pair <int, int> st[N], en[N];

bool cmp(int i, int j) {
	return st[i] != st[j] ? st[i] < st[j] : en[i] < en[j];
}

bool ok() {
	for (int i = 0; i < 4; i ++) if (st[i].first != en[i].first && st[i].second != en[i].second) return 0;
for (int i = 0; i < 3; i ++) if (st[id[i]] == st[id[i+1]] && en[id[i]] == en[id[i+1]]) return 0;
	if (st[id[0]] != st[id[1]] || en[id[0]] != st[id[2]] || en[id[1]] != st[id[3]] || en[id[2]] != en[id[3]]) return 0;
	return 1;
}

int main() {
//	freopen("c.in", "r", stdin);
	for (int i = 0; i < 4; i ++) {
		scanf("%d %d %d %d", &st[i].first, &st[i].second, &en[i].first, &en[i].second);
		if (st[i] > en[i]) swap(st[i], en[i]);
	}
	for (int i = 0; i < 4; i ++) id[i] = i;
	sort(id, id + 4, cmp);
	if (ok()) puts("YES");
	else puts("NO");
	return 0;
}