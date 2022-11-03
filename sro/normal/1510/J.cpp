#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

char s[100005];
int t[100005];
int n;

bool check(int k) {
	int lst = -1;
	memset(t, 0, sizeof(t));
	circ(i, n - k + 1, n) if (s[i] == '#') return 0;
	if (n - k - 1 > 0 && s[n - k] == '_' && s[n - k - 1] == '#') return 0;
	cont(i, n - k) if (s[i] == '#') {
		if (s[i - 1] == '#') {
			lst = i;
			t[i] = 1;
			continue;
		}
		int ls = i - k;
		if (ls - 1 <= lst) return 0;
		circ(j, ls, i) t[j] = 1;
		lst = i;
	}
	cont(i, n - k) {
		if (!t[i] && !t[i - 1] && !t[i + 1]) {
			if (k <= 0) return 0;
			t[i] = 2;
		}
		if (!t[i] && !t[i - 1] && t[i + 1]) {
			if (k <= 1) return 0;
			if (t[i - 2] == 1) return 0;
			t[i - 1] = 2;
		}
	}
	if (n - k > 0 && !t[n - k]) {
		if (k <= 1) return 0;
		t[n - k] = 2;
	}
	if (n - k > 0 && !t[1]) return 0;
	vector<int> ans;
	int cs = 0;
	cont(i, n - k) {
		if (t[i]) ++cs;
		else {
			if (cs) ans.pub(cs);
			cs = 0;
		}
	}
	if (cs) ans.pub(cs);
	printf("%d\n", SZ(ans));
	loop(i, SZ(ans)) printf("%d%c", ans[i], " \n"[i == SZ(ans) - 1]);
	return 1;
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	loop(i, 4) if (check(i)) return 0;
	puts("-1"); return 0;
}