//In the name of God

#include <bits/stdc++.h>

using namespace std;

const int S = 1e6 + 49;
const int N = 2e5 + 49;
const int mod = 1e9 + 7;

int n ; 
vector<int> p[S], qu[N];
int isp[S], inv[S], last[S], val[S], deval[S], ans[N];
int ql[N], qr[N], fen[N], a[N];

int pw (int a, int b) {
	return b? pw(a * 1LL * a % mod, b >> 1) * 1LL * (b & 1? a : 1) % mod: 1;	
}

void update (int m, int x) { m++;
	while (m < N)
		fen[m] = fen[m] * 1LL * x % mod, m += m & (-m);
}

int query (int m) {
	int res = 1;
	while (m)
		res = res * 1LL * fen[m] % mod, m -= m & (-m);
	return res;
}

int query (int l, int r) {
	return query(r) * 1LL * pw(query(l), mod - 2) % mod;
}

int main () {
	memset(last, -1, sizeof (last));
	ios_base :: sync_with_stdio(0);
	for (int i = 0; i < N; i++) fen[i] = 1;
	for (int i = 1; i < S; i++) inv[i] = pw(i, mod - 2), val[i] = (i - 1) * 1LL * inv[i] % mod, deval[i] = pw(val[i], mod - 2);
	for (int i = 2; i < S; i++)
		if (!isp[i]) {
			for (int j = i; j < S; j += i)
				p[j].push_back(i), isp[j] = 1;
		}
		
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		update(i, a[i]);
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> ql[i] >> qr[i]; ql[i]--;
		qu[qr[i] - 1].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		int r = i + 1;
		for (int x : p[a[i]]) {
			if (last[x] != -1)
				update(last[x], deval[x]);
			last[x] = i;
			update(i, val[x]);
		}
		for (int id : qu[i]) {
			int l = ql[id];
			ans[id] = query(l, r);
		}
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << '\n';
}