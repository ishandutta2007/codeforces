#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, ll> PIL;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

const ll INF = 1LL<<62;
#define N 1000100
int n; ll kk;
ll w[N], pw[N];
int fa[N];

int pl[N], pr[N], pc[N];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> kk;
	for (int i = 1; i < n; i ++) {
		int x; ll y;
		cin >> x >> y;
		x--;
		w[i] = w[x]^y;
		fa[i] = x;
	}
	memcpy(pw, w, sizeof w);
	sort(pw, pw+n);
	for (int i = 0; i < n; i ++) pr[i] = n;
	ll le = 0, ri = INF;
	ll S = 0;
	for (int p = 61; p >= 0; p--) {
		ll mi = le + (ri-le)/2;
		ll T = S;

		//cout << p << " " << S << endl;
		//cout << mi << endl;
		for (int i = 0; i < n; i ++) {
			pc[i] = lower_bound(pw+pl[i], pw+pr[i], mi^(pw[i]>>p+1<<p+1)) - pw;
			//printf("%d %d %d %d\n", i, pl[i], pr[i], pc[i]);
			if ((pw[i] >> p)&1) T += pr[i] - pc[i]; else T += pc[i] - pl[i];
		}

		if (T >= kk) {
			ri = mi;
			for (int i = 0; i < n; i ++) {
				if ((pw[i] >> p)&1) {
					pl[i] = pc[i];
				} else {
					pr[i] = pc[i];
				}
			}
		} else {
			le = mi;
			S = T;
			for (int i = 0; i < n; i ++) {
				if ((pw[i] >> p)&1) {
					pr[i] = pc[i];
				} else {
					pl[i] = pc[i];
				}
			}
		}
	}
	cout << le << endl;
	return 0;
}