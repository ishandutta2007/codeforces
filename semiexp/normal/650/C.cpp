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

int H, W, A[1010101];
int ans[1010101];
vector<pair<int, int> > vs;
int idx;

int nrow[1010101], ncol[1010101];

int uf[1010101];
int ia[1010101];

int root(int p)
{
	return uf[p] < 0 ? p : (uf[p] = root(uf[p]));
}
void join(int p, int q)
{
	p = root(p)
		;
	q = root(q);
	if (p == q) return;
	uf[p] += uf[q];
	uf[q] = p;
}

int main()
{
	scanf("%d%d", &H, &W);
	for (int i = 0; i < H * W; ++i) scanf("%d", A + i);
	for (int i = 0; i < H * W; ++i) {
		vs.push_back({ A[i], i });
		uf[i] = -1;
	}
	sort(vs.begin(), vs.end());
	
	idx = 0;
	int p = 0;
	while (p < vs.size()) {
		int p2 = p;
		while (p2 < vs.size() && vs[p2].first == vs[p].first) ++p2;

		vector<pair<int, int> > waf;
		for (int i = p; i < p2; ++i) waf.push_back({ vs[i].second / W, vs[i].second % W });
		sort(waf.begin(), waf.end());
		for (int i = 1; i < waf.size(); ++i) if (waf[i].first == waf[i - 1].first) join(waf[i].first * W + waf[i].second, waf[i - 1].first * W + waf[i - 1].second);
		waf.clear();
		for (int i = p; i < p2; ++i) waf.push_back({ vs[i].second % W, vs[i].second / W });
		sort(waf.begin(), waf.end());
		for (int i = 1; i < waf.size(); ++i) if (waf[i].first == waf[i - 1].first) join(waf[i].first + waf[i].second * W, waf[i - 1].first + waf[i - 1].second * W);
		waf.clear();

		vector<pair<int, int> > cands; // val, pos
		for (int i = p; i < p2; ++i) {
			int r = vs[i].second / W, c = vs[i].second % W;
			int v = max(nrow[r] + 1, ncol[c] + 1);
			cands.push_back({ v, i });
			ia[root(vs[i].second)] = max(ia[root(vs[i].second)], v);
		}

		sort(cands.begin(), cands.end());
		reverse(cands.begin(), cands.end());
		for (auto a : cands) {
			int i = a.second;
			int r = vs[i].second / W, c = vs[i].second % W;
			int v = ans[vs[i].second] = ia[root(vs[i].second)];
			nrow[r] = max(nrow[r], v);
			ncol[c] = max(ncol[c], v);
		}

		p = p2;
	}
	for (int i = 0; i < H * W; ++i) {
		printf("%d%c", ans[i], ((i + 1) % W == 0 ? '\n' : ' '));
	}
	return 0;
}