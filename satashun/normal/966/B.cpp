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

int main() {
	int n, x1, x2; cin >> n >> x1 >> x2;
	bool rev = false;

	vector<pii> vec(n);
	rep(i, n) {
		int c; cin >> c;
		vec[i] = mp(c, i);
	}

	sort(ALL(vec));

	rep(rev, 2) {
		rep(i, n) {
			int m = vec[i].fi;
			int need = x1 / m;
			if (need * m < x1) {
				++need;
			}

			if (need + i >= n) {
				continue;
			}

			int j = i + need;
			int m2 = vec[j].fi;

			if ((ll)m2 * (n - j) < x2) {
				continue;
			}

			vi ans[2];
			for (int k = i; k < j; ++k) {
				ans[rev].pb(vec[k].se);
			}
			for (int k = j; k < n; ++k) {
				ans[rev ^ 1].pb(vec[k].se);
			}

			puts("Yes");
			int k1 = ans[0].size(), k2 = ans[1].size();
			printf("%d %d\n", k1, k2);
			rep(i, k1) {
				printf("%d%c", ans[0][i] + 1, i == k1 - 1 ? '\n' : ' ');
			}
			rep(i, k2) {
				printf("%d%c", ans[1][i] + 1, i == k2 - 1 ? '\n' : ' ');
			}
			return 0;	
		}

		swap(x1, x2);
	}

	puts("No");

	return 0;
}