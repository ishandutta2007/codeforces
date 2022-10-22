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

int n, k, q;
int a[5010];
bool f[10000010];

int main() {
	cin >> n >> k;

	rep(i, n) {
		cin >> a[i];
		f[a[i]] = 1;
	}

	cin >> q;

	while (q--) {
		int x;
		cin >> x;
		int ret = 30;

		rep(i, n) {
			for (int j = 1; j <= k; ++j) {
				int zan = x - a[i] * j;

				if (zan < 0) break;
				else if (zan == 0) {
					ret = min(ret, j);
					break;
				}

				for (int u = 1; u <= k - j; ++u) {
					if (zan % u == 0) {
						int r = zan / u;
						if (r >= 0 && r <= 10000000 && f[r]) {
							ret = min(ret, u + j);
							break;
						}
					}
				}
			}
		}

		if (ret == 30) ret = -1;
		cout << ret << endl;
	}

	return 0;
}