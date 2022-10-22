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
vector<ll> sqs;

int main() {
	for (ll i = 1; i <= 1000000; ++i) sqs.pb(i*i);
	cin >> n;
	ll u = 2;

	for (ll i = 1; i <= n; ++i) {
		auto it = upper_bound(ALL(sqs), u/(i*(i+1)*(i+1)));
		ll t = *it * (i*(i+1)*(i+1)) - u/i;
		printf("%I64d\n", t);
		u = i * (i+1) * (it-sqs.begin()+1);
	}
	return 0;
}