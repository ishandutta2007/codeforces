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
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

int get(ll x) {
	int s = 0;
	while (x) {
		s += x % 10;
		x /= 10;
	}
	return s;
}

int main() {
	ll n; cin >> n;
	int ans = get(n);

	ll k = 1;
	for (int i = 0; i <= 12; ++i) {
		ll u = n % k;
		ll v = n - u - 1;
		if (u+1 >= 0ll && v >= 0ll) {
			ans = max(ans, get(u+1) + get(v));
		}
		k *= 10;
	}
	cout << ans << endl;

	return 0;
}