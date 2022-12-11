#include <bits/stdc++.h>
using namespace std;

int a[150010], b[150010], c[150010], d[150010];
vector <int> G12[150010], G23[150010], G34[150010];
multiset <int> S;

int main () {
	int A, B, C, D; scanf("%d%d%d%d", &A, &B, &C, &D);
	for (int i = 0; i < A; i++) scanf("%d", &a[i]);
	for (int i = 0; i < B; i++) scanf("%d", &b[i]);
	for (int i = 0; i < C; i++) scanf("%d", &c[i]);
	for (int i = 0; i < D; i++) scanf("%d", &d[i]);
	int M1; scanf("%d", &M1);
	for (int i = 0; i < M1; i++) {
		int x, y; scanf("%d%d", &x, &y), x--, y--;
		G12[y].push_back(x);
	}
	int M2; scanf("%d", &M2);
	for (int i = 0; i < M2; i++) {
		int x, y; scanf("%d%d", &x, &y), x--, y--;
		G23[x].push_back(y);
	}
	int M3; scanf("%d", &M3);
	for (int i = 0; i < M3; i++) {
		int x, y; scanf("%d%d", &x, &y), x--, y--;
		G34[x].push_back(y);
	}
	for (int i = 0; i < A; i++) S.insert(a[i]);
	for (int i = 0; i < B; i++) {
		for (auto x : G12[i]) S.erase(S.find(a[x]));
		b[i] += S.size() ? *S.begin() : 500000000;
		for (auto x : G12[i]) S.insert(a[x]);
	}
	S.clear();
	for (int i = 0; i < D; i++) S.insert(d[i]);
	for (int i = 0; i < C; i++) {
		for (auto x : G34[i]) S.erase(S.find(d[x]));
		c[i] += S.size() ? *S.begin() : 500000000;
		for (auto x : G34[i]) S.insert(d[x]);
	}
	S.clear();
	for (int i = 0; i < C; i++) S.insert(c[i]);
	int ans = 2000000000;
	for (int i = 0; i < B; i++) {
		for (auto x : G23[i]) S.erase(S.find(c[x]));
		ans = min(ans, b[i] + (S.size() ? *S.begin() : 500000000));
		for (auto x : G23[i]) S.insert(c[x]);
	}
	if (ans >= 450000000) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}