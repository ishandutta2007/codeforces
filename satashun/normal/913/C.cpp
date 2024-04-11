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

int n;
ll L;
ll c[32];

int main() {
	cin >> n >> L;

	rep(i, 32) c[i] = LLONG_MAX;
	rep(i, n) cin >> c[i];

	for (int i = 1; i < 32; ++i) {
		c[i] = min(c[i], c[i-1] * 2);
	}

	ll ret = LLONG_MAX;

	rep(i, 32) if (L <= (1LL << i)) {
		ret = min(ret, c[i]);
	}

	vi vec;

	while (L) {
		vec.pb(L & 1);
		L /= 2;
	}

	ll t = 0;

	for (int i = (int)vec.size()-1; i >= 0; --i) {
		if (vec[i]) {
			t += c[i];
		} else {
			ret = min(ret, t + c[i]);
		}
	}
	ret = min(ret, t);
	cout << ret << endl;

	return 0;
}