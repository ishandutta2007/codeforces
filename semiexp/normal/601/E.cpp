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

int N, K, Q;
vector<pair<int, int> > item;
vector<pair<int, int> > eve;
int ileft[30303], iright[30303];

const int DEPTH = 16;
vector<int> appends[2 << DEPTH];

void app(int p, int ql, int qr, int v, int dep)
{
	int pl = (p << dep), pr = (p + 1) << dep;
	if (pr <= ql || qr <= pl) return;
	if (ql <= pl && pr <= qr) {
		appends[p].push_back(v);
		return;
	}
	app(p * 2, ql, qr, v, dep - 1);
	app(p * 2 + 1, ql, qr, v, dep - 1);
}

void apply(vector<int> &dp, int v, int w)
{
	for (int i = K; i >= w; --i) dp[i] = max(dp[i], dp[i - w] + v);
}
int vhash(vector<int> &dp)
{
	const int P = 1e7 + 19;
	const int Q = 1e9 + 7;

	i64 ret = 0;
	i64 m = 1;
	for (int i = 1; i <= K; ++i) {
		ret = (ret + m * dp[i]) % Q;
		m = m * P % Q;
	}
	return (int)ret;
}

vector<int> ret;

void solve(int p, vector<int> dp)
{
	for (int i : appends[p]) {
		apply(dp, item[i].first, item[i].second);
	}
	if (p >= (1 << DEPTH)) {
		// leaf
		p -= 1 << DEPTH;
		if (p < eve.size() && eve[p].first == 3) {
			ret.push_back(vhash(dp));
		}
	} else {
		solve(p * 2, dp);
		solve(p * 2 + 1, dp);
	}
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		int v, w;
		scanf("%d%d", &v, &w);
		item.push_back({ v, w });
		eve.push_back({ 1, i });
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		int ki;
		scanf("%d", &ki);
		if (ki == 1) {
			int v, w;
			scanf("%d%d", &v, &w);
			eve.push_back({ 1, (int)item.size() });
			item.push_back({ v, w });
		} else if (ki == 2) {
			int x;
			scanf("%d", &x);
			eve.push_back({ 2, x - 1 });
		} else {
			eve.push_back({ 3, -1 });
		}
	}
	for (int i = 0; i < item.size(); ++i) {
		ileft[i] = 0;
		iright[i] = eve.size();
	}
	for (int i = 0; i < eve.size(); ++i) {
		if (eve[i].first == 1) ileft[eve[i].second] = i;
		if (eve[i].first == 2) iright[eve[i].second] = i;
	}
	for (int i = 0; i < item.size(); ++i) {
	//	printf("%d: [%d, %d)\n", i, ileft[i], iright[i]);
		app(1, ileft[i] + (1 << DEPTH), iright[i] + (1 << DEPTH), i, DEPTH);
	}
	solve(1, vector<int>(K + 1, 0));
	for (int r : ret) printf("%d\n", r);

	return 0;
}