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

const int MX = 7010;
const int MN = 100010;

bitset<MX> b[MN];
bitset<MX> coef[MX];
vi divs[MX];

int main() {
	for (int i = 1; i < MX; ++i) {
		for (int j = i; j < MX; j += i) {
			divs[j].pb(i);
		}
	}

	for (int i = MX-1; i >= 1; --i) {
		coef[i].set(i, 1);
		for (int j = i * 2; j < MX; j += i) {
			coef[i] = coef[i] ^ coef[j];
		}
	}

	int n, q; scanf("%d %d", &n, &q);

	string ans;

	rep(i, q) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int x, v;
			scanf("%d %d", &x, &v);
			--x;
			b[x].reset();

			for (int d : divs[v]) {
				b[x].set(d, 1);
			}

		} else if (tp == 2) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			--x; --y; --z;
			b[x] = b[y] ^ b[z];
		} else if (tp == 3) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			--x; --y; --z;
			b[x] = b[y] & b[z];
		} else if (tp == 4) {
			int x, v;
			scanf("%d %d", &x, &v);
			--x;

			int f = ((b[x] & coef[v]).count()) & 1;
			ans.pb('0' + (int)f);
		}
	}

	cout << ans << endl;
	return 0;
}