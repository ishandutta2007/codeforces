// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 4e5 + 10;
const ll N = 26;

int sg[N][MAXN], lz[N][MAXN], n, q, cnt[N];

inline void push(int ind, int l, int r, int v) {
	int x = lz[ind][v];
	if (x >= 0) {
		sg[ind][v] = x * (r - l + 1);
		if ((v << 1 | 1) < MAXN) {
			lz[ind][v << 1] = x;
			lz[ind][v << 1 | 1] = x;
		}	

		lz[ind][v] = -1;
	}
}

void update(int ind, int ql, int qr, int val, int l = 1, int r = n, int v = 1) {
	push(ind, l, r, v);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		lz[ind][v] = val;
		push(ind, l, r, v);
		return;
	}

	int mid = (l + r) >> 1;
	update(ind, ql, qr, val, l, mid, v << 1);
	update(ind, ql, qr, val, mid + 1, r, v << 1 | 1);
	sg[ind][v] = sg[ind][v << 1] + sg[ind][v << 1 | 1];
}

int query(int ind, int ql, int qr, int l = 1, int r = n, int v = 1) {
	push(ind, l, r, v);
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) return sg[ind][v];

	int mid = (l + r) >> 1;
	return query(ind, ql, qr, l, mid, v << 1) + 
		query(ind, ql, qr, mid + 1, r, v << 1 | 1);
}

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	for (int i = 0; i < N; i++)
		fill(lz[i], lz[i] + MAXN, -1);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		update(c - 'a', i, i, 1);
	}

	while (q--) {
		int l, r, t = 0;
		cin >> l >> r;

		for (int i = 0; i < N; i++) cnt[i] = query(i, l, r), t += (cnt[i] & 1);
		if (t > 1) continue;
		for (int i = 0; i < N; i++) update(i, l, r, 0);
	
		int ind = 0, j = -1;
		for (int c = 0; c < N; c++) {
			if (cnt[c]) {
				update(c, l + ind, l + ind + cnt[c] / 2 - 1, 1);
				update(c, r - ind - cnt[c] / 2 + 1, r - ind, 1);
				ind += cnt[c] / 2;
			}	

			if (cnt[c] & 1) j = c;
		}
		
		if (j >= 0)
			update(j, l + ind, l + ind, 1);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < N; j++) {
			if (query(j, i, i)) {
				cout << char(j + 'a');
				break;
			}
		}
	}

	cout << endl;
	return 0;
}