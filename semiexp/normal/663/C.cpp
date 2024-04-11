#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, M;
int U[101010], V[101010], C[101010];

int uf[202020];

int root(int p)
{
	return uf[p] < 0 ? p : (uf[p] = root(uf[p]));
}
void join(int p, int q)
{
	p = root(p);
	q = root(q);
	if (p == q) return;
	if (uf[p] > uf[q]) swap(p, q);
	uf[p] += uf[q];
	uf[q] = p;
}
bool chk[202020];
bool use[202020];

vector<int> solve(int target)
{
	vector<int> ans;
	for (int i = 0; i < 2 * N; ++i) {
		uf[i] = -1;
		if (i % 2 == 0) uf[i] = -2;
		chk[i] = false;
		use[i] = false;
	}
	for (int i = 0; i < M; ++i) {
		if (C[i] == target) {
			join(U[i] * 2, V[i] * 2);
			join(U[i] * 2 + 1, V[i] * 2 + 1);
		} else {
			join(U[i] * 2, V[i] * 2 + 1);
			join(U[i] * 2 + 1, V[i] * 2);
		}
	}
	for (int i = 0; i < N; ++i) {
		if (root(2 * i) == root(2 * i + 1)) return{ -1 };
	}

	for (int i = 0; i < N; ++i) {
		int ra = root(2 * i), rb = root(2 * i + 1);
		if (chk[ra] || chk[rb]) continue;
		chk[ra] = chk[rb] = true;
		if (-uf[ra] < -uf[rb]) use[ra] = true;
		else use[rb] = true;
	}
	for (int i = 0; i < N; ++i) {
		if (use[root(2 * i)]) ans.push_back(i + 1);
	}
	return ans;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int u, v;
		char c[2];
		scanf("%d%d%s", &u, &v, c);

		U[i] = u - 1;
		V[i] = v - 1;
		C[i] = (c[0] == 'R' ? 1 : 0);
	}

	vector<int> ans1 = solve(0), ans2 = solve(1);
	ans1.push_back(4);
	ans2.push_back(4);
	if (ans1[0] == -1 && ans2[0] == -1) {
		puts("-1");
		return 0;
	}
	if (ans1[0] == -1 || (ans2[0] != -1 && ans1.size() > ans2.size())) swap(ans1, ans2);
	ans1.pop_back();
	printf("%d\n", ans1.size());
	for (int i = 0; i < ans1.size(); ++i) {
		printf("%d", ans1[i]);
		if (i != ans1.size() - 1) printf(" ");
	}
	puts("");
	return 0;
}