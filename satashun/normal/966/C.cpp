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

int p[60];
vector<ll> num[60];

int main() {
	int n; cin >> n;
	vector<ll> b(n);

	rep(i, n) {
		cin >> b[i];
		for (int j = 60; j >= 0; --j) {
			if ((b[i] >> j) & 1) {
				num[j].pb(b[i]);
				break;
			}
		}
	}

	vi cnt(60);
	vector<ll> ans;

	rep(i, n) {
		rep(j, 60) {
			if (cnt[j] == 0 && p[j] < num[j].size()) {
				ll x = num[j][p[j]++];
				ans.pb(x);
				rep(k, 60) {
					if ((x >> k) & 1) {
						cnt[k] ^= 1;
					}
				}
				break;
			}
		}
	}

	if (ans.size() == n) {
		puts("Yes");
		rep(i, n) printf("%I64d%c", ans[i], i == n-1 ? '\n' : ' ');
	} else {
		puts("No");
	}

	return 0;
}