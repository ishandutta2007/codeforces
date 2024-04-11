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

ll n, l, r;
int ret;

int get(ll x, ll p)
{
	if (x < 2) return x;
	int c = 0;
	ll xx = x;

	while (xx > 0) {
		++c;
		xx >>= 1;
	}
	--c;

	if (p == (1LL << c)) {
		return x % 2;
	}

	if (p < (1LL << c)) {
		return get(x / 2, p);
	}

	return get(x / 2, p - (1LL << c));
}

int main() {
	cin >> n >> l >> r;

	for (ll i = l; i <= r; ++i) {
		ret += get(n, i);
	}

	cout << ret << endl;

	return 0;
}