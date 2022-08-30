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

int N;
vector<pair<int, int> > child[505050];
int tbl[1 << 22];
int ans[505050];
int ssize[505050];

int check(vector<pair<int, int> > *lg, int mask, int dep)
{
	int ret = tbl[mask];
	for (int i = 0; i < 22; ++i) ret = max(ret, tbl[mask ^ (1 << i)]);
//	lg->push_back({ mask, dep });
//	tbl[mask] = max(tbl[mask], dep);
	if (ret < 0) return -1;
	return ret + dep;
}
void clear_tbl(vector<pair<int, int> > *lg)
{
	for (auto p : *lg) tbl[p.first] = -1;
}

int comp_ssize(int p)
{
	ssize[p] = 1;
	for (auto e : child[p]) ssize[p] += comp_ssize(e.first);
	return ssize[p];
}

vector<pair<int, int> > *solve(int p, int mask, int dep)
{
	if (child[p].size() == 0) {
		auto ret = new vector<pair<int, int> >;
		ret->push_back({ mask, dep });
		tbl[mask] = max(tbl[mask], dep);
		ans[p] = 0;
		return ret;
	}

	vector<pair<int, int> > child_ord;
	for (int i = 0; i < child[p].size(); ++i) {
		child_ord.push_back({ ssize[child[p][i].first], i });
	}
	sort(child_ord.begin(), child_ord.end());
//	reverse(child_ord.begin(), child_ord.end());
	
	vector<vector<pair<int, int> >*> chs;
	vector<pair<int, int> > *lg;
	for (int i = 0; i < child_ord.size(); ++i) {
		auto ch = child[p][child_ord[i].second];
		auto *tmp = solve(ch.first, mask ^ (1 << ch.second), dep + 1);
		if (i != child_ord.size() - 1) {
			chs.push_back(tmp);
			clear_tbl(tmp);
		} else {
			lg = tmp;
		}
		ans[p] = max(ans[p], ans[ch.first]);
	}
	int s = 0;
	for (auto v : chs) {
		for (auto e : *v) {
			int tmp = check(lg, e.first, e.second);
	//		printf("%d %d,%d %d\n", p, e.first, e.second, tmp);
			s = max(s, tmp);
		}
		for (auto e : *v) {
			lg->push_back(e);
			tbl[e.first] = max(tbl[e.first], e.second);
		}
		delete v;
	}
	s = max(s, check(lg, mask, dep));
	lg->push_back({ mask, dep });
	tbl[mask] = max(tbl[mask], dep);
	ans[p] = max(ans[p], s - 2 * dep);
	//printf("%d %d %d\n", s, dep, ans[p]);
	//printf("%d: ", p);
	//for (auto a : *lg) printf("%d,%d ", a.first, a.second);
	///puts("");
	return lg;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		int p;
		char c[5];
		scanf("%d%s", &p, c);
		child[p - 1].push_back({ i + 1, (int)(c[0] - 'a') });
	}
	for (int i = 0; i < (1 << 22); ++i) tbl[i] = -1;

	comp_ssize(0);
	solve(0, 0, 0);
	for (int i = 0; i < N; ++i) printf("%d%c", ans[i], i == N - 1 ? '\n' : ' ');
	return 0;
}