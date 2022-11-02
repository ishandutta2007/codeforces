#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define find find228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1e7;

int tree[MAXN][2];
int cnt[MAXN];

int root = 1;
int sz = 1;
const int MAXLOG = 30;

void add(int x) {
	int now = root;
	for (int i = MAXLOG; i >= 0; i--) {
		int nxt = (x >> i) & 1;
		cnt[now]++;
		if (!tree[now][nxt]) {
			sz++;
			tree[now][nxt] = sz;
		}
		now = tree[now][nxt];
	}
	cnt[now]++;
}

void del(int x) {
	int now = root;
	for (int i = MAXLOG; i >= 0; i--) {
		int nxt = (x >> i) & 1;
		cnt[now]--;
		assert(tree[now][nxt]);
		now = tree[now][nxt];
	}
	cnt[now]--;
}

int find(int x) {
	int ans = 0;
	int now = root;
	for (int i = MAXLOG; i >= 0; i--) {
		int need = (x >> i) & 1;
		if (!tree[now][need] || !cnt[tree[now][need]]) need ^= 1;
		assert(tree[now][need]);
		ans |= (1LL << i) * need;
		now = tree[now][need];
	}
	return ans;
}

int n;
vector<int> a;
void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		add(x);
	}
	for (int i = 0; i < n; i++) {
		int x = find(a[i]);
		del(x);
		cout << (x ^ a[i]) << " ";
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}