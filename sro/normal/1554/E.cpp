#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

const int jt = 998244353;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = (ll)a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return (ll)a * b % jt; }

int N;
vector<int> nei[100005];
int dp[100005][205], res[205], ans[100005];
int siz[100005];
vector<int> ins;

void dfs(int now, int lst) {
	siz[now] = 1;
	for (int to : nei[now]) if (to != lst) dfs(to, now), siz[now] += siz[to];
	rep(i, SZ(ins)) {
		if (siz[now] % ins[i] <= 1) {
			int val = 1;
			for (int to : nei[now]) if (to != lst) mul(val, dp[to][i]);
			dp[now][i] = (ins[i] == 1 && now != 1) ? Add(val, val) : val;
		}
		else dp[now][i] = 0;
	}
}

void solve() {
	scanf("%d", &N);
	repi(i, N) nei[i].clear();
	rep(i, N - 1) {
		int a, b; scanf("%d%d", &a, &b);
		nei[a].push_back(b); nei[b].push_back(a);
	}
	ins.clear();
	for (int i = 1; i * i <= N - 1; ++i) if ((N - 1) % i == 0) {
		ins.push_back(i);
		if (i * i != N - 1) ins.push_back((N - 1) / i);
	}
	sort(ins.begin(), ins.end());
	dfs(1, 0);
	rep(i, SZ(ins)) res[i] = dp[1][i];
	for (int i = SZ(ins) - 1; ~i; --i) for (int j = SZ(ins) - 1; j > i; --j) if (ins[j] % ins[i] == 0) sub(res[i], res[j]);
	repi(i, N) ans[i] = 0;
	rep(i, SZ(ins)) ans[ins[i]] = res[i];
	repi(i, N) printf("%d%c", ans[i], " \n"[i == N]);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}