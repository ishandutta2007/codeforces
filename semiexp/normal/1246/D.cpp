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

int N, P[101010];
vector<int> ch[101010];
pair<int, int> nleaf[101010];
pair<int, int> dleaf[101010];
int dep[101010];
bool pedge[101010];

void dfs1(int p)
{
	if (p == 0) dep[p] = 0;
	else dep[p] = dep[P[p]] + 1;

	if (ch[p].size() == 0) {
		nleaf[p] = make_pair(0, p);
		dleaf[p] = make_pair(0, p);
	} else {
		nleaf[p] = make_pair(10101010, -1);
		dleaf[p] = make_pair(-1, -1);
		for (int q : ch[p]) {
			dfs1(q);
			nleaf[p] = min(nleaf[p], nleaf[q]);
			dleaf[p] = max(dleaf[p], dleaf[q]);
		}
		nleaf[p].first += 1;
		dleaf[p].first += 1;
	}
}

vector<int> ans1;
vector<int> ans2;

void solve(int p)
{
	ans1.push_back(p);
	if (ch[p].size() == 0) return;

	int ld = -1;
	for (int i = 0; i < 2; ++i) {
		for (int q : ch[p]) if (pedge[q] == (i == 1)) {
			if (ld != -1) {
				for (int j = 0; j < dep[ld] - dep[p]; ++j) {
					ans2.push_back(q);
				}
			}
			solve(q);
			ld = ans1[ans1.size() - 1];
		}
	}
}

void show_array(vector<int> &a)
{
	for (int i = 0; i < a.size(); ++i) {
		if (i != 0) printf(" ");
		printf("%d", a[i]);
	}
	puts("");
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i < N; ++i) {
		scanf("%d", P + i);
		ch[P[i]].push_back(i);
	}
	dfs1(0);

	int pt = 0;
	while (ch[pt].size() > 0) {
		for (int q : ch[pt]) {
			if (dleaf[pt].second == dleaf[q].second) {
				pt = q;
				break;
			}
		}
		pedge[pt] = true;
	}
	solve(0);
	show_array(ans1);
	printf("%d\n", (int)ans2.size());
	show_array(ans2);
	return 0;
}