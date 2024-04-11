#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define foreach(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n;
int a[1 << 20];
int lgl[1 << 20];
vector<int> stk;

bool dfs(int now) {
	stk.pub(now);
	if (lgl[now] == 2) {
		vector<int> ans;
		do ans.pub(stk.back()), stk.pob(); while (stk.back() != now);
		printf("%d\n", SZ(ans));
		loop(i, SZ(ans)) printf("%d%c", ans[i], " \n"[i == SZ(ans) - 1]);
		return 1;
	}
	lgl[now] = 2;
	if (dfs(a[now])) return 1;
	else return lgl[now] = 1, 0;
}

void solve() {
	scanf("%d", &n);
	cont(i, n) scanf("%d", a + i), a[i] = i - a[i];
	cont(i, n) lgl[i] = 0;
	cont(i, n) if (!lgl[i] && dfs(i)) return;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}