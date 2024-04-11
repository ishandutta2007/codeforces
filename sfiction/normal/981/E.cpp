#include <bits/stdc++.h>

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <class T> void mini(T &l, T r){l = min(l, r);}
template <class T> void maxi(T &l, T r){l = max(l, r);}

template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
	while (*sdbg != ',') cerr << *sdbg++; cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
	os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
	return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef SFIC
	#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
	#define eput(...) 218
#endif

const int N = 1E4 + 10;

typedef pair<pii, int> ppi;
typedef bitset<N> BS;

BS ans;

void solve(vector<ppi> &a, BS f, int L, int R){
	eput(a, f.to_string(), L, R);

	vector<ppi> b[2];
	int m = L + R >> 1;
	for (auto &x: a){
		int l = x.st.st, r = x.st.nd;
		if (l == L && r == R){
			f |= f << x.nd;
			eput(x.nd);
		}
		else{
			if (l <= m)
				b[0].emplace_back(pii(l, min(m, r)), x.nd);
			if (m < r)
				b[1].emplace_back(pii(max(m + 1, l), r), x.nd);
		}
	}
	if (L == R){
		ans |= f;
		return;
	}

	solve(b[0], f, L, m);
	solve(b[1], f, m + 1, R);
}

int main(){
	int n, q;

	scanf("%d%d", &n, &q);
	vector<ppi> a(q);
	for (int i = 0; i < n; ++i)
		scanf("%d%d%d", &a[i].st.st, &a[i].st.nd, &a[i].nd);
	BS t;
	t.set(0);
	solve(a, t, 1, n);

	vector<int> ans;
	for (int i = 1; i <= n; ++i)
		if (::ans[i])
			ans.push_back(i);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i)
		printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
	return 0;
}