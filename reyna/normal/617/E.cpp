//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 2e6 + 5, S = 349;
ll cnt[N], n, m, k, res[N], a[N];

int read() { int x; cin >> x; return x; }


pair<pair<int, int>, int> sr[N];

int cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return (a.first.first / S == b.first.first / S? a.first.second < b.first.second: a.first.first / S < b.first.first / S);
}

long long cur = 0;

int rem(int x) {
	if (k) {
		cnt[x]--;
		cur -= cnt[x ^ k];
	} else {
		cnt[x]--;
		cur -= cnt[x];
	}
}

int add(int x) {
	if (k) {
		cur += cnt[x ^ k];
		cnt[x]++;
	} else {
		cur += cnt[x];
		cnt[x]++;
	}
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read(), m = read(), k = read();
	for (int i = 0; i < n; ++i)
		cin >> a[i + 1], a[i + 1] ^= a[i];
	n++;
	for (int i = 0; i < m; ++i) {
		int l = read() - 1, r = read() + 1;
		sr[i] = {{r, l}, i};
	}
	sort(sr, sr + m, cmp);
	int pt = 0;
	int ql = 0, qr = 0;
	for (int i = 0; i < m; ++i) {
		int l = sr[i].first.second, r = sr[i].first.first, id = sr[i].second;
		while (qr < r)
			add(a[qr++]);
		while (ql > l)
			add(a[--ql]);
		while (qr > r)
			rem(a[--qr]);
		while (ql < l)
			rem(a[ql++]);
		res[id] = cur;
	}
	for (int i = 0; i < m; ++i)
		cout << res[i] << endl;
}