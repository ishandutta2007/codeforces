#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)a.size())
typedef long long ll;

int N, K;
ll a[500500], b[500500], res;

int main () {
	if (1) {
		scanf("%d %d", &N, &K);
		fo(i, 0, N) scanf("%lld", &a[i]);
		fo(i, 0, N) scanf("%lld", &b[i]);
	} else {
		srand(time(NULL));
		N = 2200, K = rand()%N;
		fo(i, 0, N) a[i] = rand()%N+5, b[i] = rand()%N+5;
		fo(i, 0, N) printf("%lld %lld\n", a[i], b[i]);
	}

	ll lo = 0, hi = 1e13;
	while (lo <= hi) {
		ll X = (lo + hi) / 2;

		ll ans = 0; int anum = 0;
		priority_queue<ll> q, bq;
		fo(i, 0, N) {
			q.push(-a[i]);
			//you can also use a b[i] to reduce ans by substituting a crappier one
			ll o1 = -q.top() + b[i] - X;
			ll o2 = bq.size() ? b[i]-bq.top() : (ll) 1e18;
			if (o1 <= o2 && o1 <= 0) {
				ans += -q.top() + b[i] - X;
				q.pop(), anum++;
				bq.push(b[i]);
			} else if (o2 < o1 && o2 < 0) {
				ans -= bq.top();
				bq.pop(), bq.push(b[i]);
				ans += b[i];
			}
		}

		if (anum >= K) {
			res = ans + X * K;
			hi = X-1;
		} else { 
			lo = X+1;
		}
	}

	printf("%lld\n", res);
	return 0;
}