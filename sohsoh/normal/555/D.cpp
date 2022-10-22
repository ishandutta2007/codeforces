#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

vector<int> vec;
int v, l, A[MAXN];
map<int, int> mp;

inline void nxt() {
	int p = v;
	auto it = lower_bound(all(vec), v + l + 1);
	v = *prev(it);
	l -= v - p;
}

inline void prv() {
	int p = v;
	v = *lower_bound(all(vec), v - l);
	l -= p - v;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
		mp[x] = i + 1;
		A[i] = x;
	}

	sort(all(vec));
	while (q--) {
		cin >> v >> l;
		v = A[v - 1];

		int a, b, c;
		a = v;
		nxt();
		b = v;
		prv();
		c = v;

		while (a != b || b != c) {
			if (a == c) {
				int d = (b - a), x = l / d;
				if (x & 1) x--;

				l -= x * d;
			}

			a = b;
			b = c;
			nxt();
			c = v;

			a = b;
			b = c;
			prv();
			c = v;
		}

		cout << mp[v] << endl;
	}
	return 0;
}