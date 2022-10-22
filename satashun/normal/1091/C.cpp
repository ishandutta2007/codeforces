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

ll calc(ll n, ll k) {
	return (n - k) * n / (k * 2) + (n / k);
}

int main() {
	int n; cin >> n;

	vector<ll> vec;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			vec.pb(calc(n, i));
			vec.pb(calc(n, n / i));
		}
	}

	sort(ALL(vec));
	vec.erase(unique(ALL(vec)), vec.end());

	int a = vec.size();
	rep(i, a) cout << vec[i] << (i == a-1 ? '\n' : ' ');

	return 0;
}