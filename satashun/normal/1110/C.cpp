#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl

vi dec(int x) {
	vi v;
	while (x > 0) {
		v.pb(x & 1);
		x /= 2;
	}
	reverse(ALL(v));
	return v;
}

int mem[30];

int main() {
	for (int i = 1; i <= 25; ++i) {
		int v = (1 << i) - 1;

		mem[i] = 1;
		for (int j = 2; j * j <= v; ++j) {
			if (v % j == 0) {
				mem[i] = max(mem[i], j);
				mem[i] = max(mem[i], v / j);
			}
		}
	}

	int q; cin >> q;
	rep(i, q) {
		int x; cin >> x;
		vi vec = dec(x);
		int sz = vec.size();

		bool zero = false;
		for (int f : vec) if (f == 0) {
			zero = true;
		}

		int ans = 0;
		if (zero) {
			ans = (1 << sz) - 1;
		} else {
			ans = mem[sz];
		}

		cout << ans << "\n";
	}
	return 0;
}