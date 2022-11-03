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

char s[200005];
int n, m;
vector<pair<int, int> > stk, si;
int cnt[26], ccn[200005];
int all, lns, mxn, ptr;

void inline jan1(int p) {
	--ccn[cnt[p]];
	--cnt[p]; --all;
	++ccn[cnt[p]];
}

void append_stk(int now, bool rem) {
	if (rem) {
		jan1(stk.back().second);
		jan1(si[now].second);
		printf("%d %d\n", ptr + 1, ptr + si[now].first);
		while (mxn && !ccn[mxn]) --mxn;
		ptr -= stk.back().first;
		if (now + 1 < m) {
			si[now + 1].first += stk.back().first;
		} else {
			lns += stk.back().first;
		}
		stk.pob();
	} else {
		stk.pub(si[now]);
		ptr += si[now].first;
	}
}

void solve() {
	scanf("%s", s);
	n = strlen(s);
	int lst = 0; all = 0;
	cont(i, n - 1) {
		if (s[i] == s[i - 1]) {
			++cnt[s[i] - 'a']; ++all;
			si.emb(i - lst, s[i] - 'a');
			lst = i;
		}
	}
	lns = n - lst; ptr = 0;
	m = SZ(si);
	mxn = 0;
	loop(i, 26) {
		++ccn[cnt[i]];
		mxn = max(mxn, cnt[i]);
	}
	printf("%d\n", max(mxn, (all + 1) / 2) + 1);
	if (mxn * 2 < all) {
		loop(i, m) append_stk(i, SZ(stk) && si[i].second != stk.back().second && mxn * 2 < all);
		si = stk; m = SZ(si); stk.clear();
	}
	int ch = -1; ptr = 0;
	loop(i, 26) if (cnt[i] == mxn) ch = i;
	loop(i, m) append_stk(i, SZ(stk) && ((stk.back().second == ch) ^ (si[i].second == ch)));
	loop(i, SZ(stk)) printf("1 %d\n", stk[i].first);
	printf("1 %d\n", lns);
	si.clear(); stk.clear(); all = lns = mxn = ptr = 0;
	memset(cnt, 0, sizeof(cnt));
	memset(ccn, 0, sizeof(int) * (n + 5));
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}