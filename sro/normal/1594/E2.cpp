#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int jt = 1000000007;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = (ll)a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return (ll)a * b % jt; }

int inline ksmii(int a, ll b) {
	int res = 1;
	while (b) {
		if (b & 1) mul(res, a);
		mul(a, a); b >>= 1;
	}
	return res;
}

map<char, int> mci;
int K, N;
ll a[2005];
int c[2005];
vector<int> pat[2005];
set<ll> kns;
map<ll, int> ins;

vector<int> operator * (const vector<int> &a, const vector<int> &b) {
	vector<int> c(6);
	for (int i = 0; i < 6; ++i) for (int j = 0; j < 6; ++j) {
		if (i == j || (i ^ 1) == j) continue;
		add(c[i], Mul(a[i], b[j]));
	}
	return c;
}

vector<int> dfs(ll now, int dep) {
	if (!kns.count(now)) return pat[dep];
	vector<int> ans = {1, 1, 1, 1, 1, 1};
	if (ins.count(now)) {
		int co = ins[now];
		for (int j = 0; j < 6; ++j) if (j != co) ans[j] = 0;
	}
	if (dep == 1) return ans;
	ans = ans * dfs(now << 1, dep - 1);
	ans = ans * dfs(now << 1 | 1, dep - 1);
	return ans;
}

int main() {
	mci['w'] = 0; mci['y'] = 1;
	mci['g'] = 2; mci['b'] = 3;
	mci['r'] = 4; mci['o'] = 5;
	scanf("%d%d", &K, &N);
	for (int i = 1; i <= N; ++i) {
		char tmp[11];
		scanf("%lld%s", a + i, tmp);
		c[i] = mci[tmp[0]];
		ll na = a[i];
		while (na) {
			kns.insert(na);
			na >>= 1;
		}
		ins[a[i]] = c[i];
	}
	for (int i = 1; i <= K; ++i) {
		int val = ksmii(4, (1ll << i) - 2);
		for (int j = 0; j < 6; ++j) pat[i].push_back(val);
	}
	vector<int> as = dfs(1, K);
	int ans = 0;
	for (int i : as) add(ans, i);
	printf("%d\n", ans);
	return 0;
}