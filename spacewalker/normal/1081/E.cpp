/*
S + x? + xk = b^2 is a perfect square
where S + x? = a^2
xk = (b - a)(b + a)
xk <= 2e5, so we can compute ahead of time all possible (b-a)(b+a) = ef pairs
then b = (e+f)/2, a = (f-e)/2

note that here, a^2 >= S
we have to check all pairs (e, f), and get one that minimizes b, such that a^2 >= S. 
*/

#include <cstdio>
#include <vector>
#include "algorithm"
#include "utility"

using namespace std;
typedef long long ll;

constexpr int NMAX = 200010;

vector<vector<int>> divList(NMAX);

int main() {
	for (int i = 1; i < NMAX; ++i) {
		for (int j = i; j < NMAX; j += i) {
			divList[j].push_back(i);
		}
	}
	int n; scanf("%d", &n);
	vector<int> halfarr(n/2);
	for (int i = 0; i < n/2; ++i) {
		scanf("%d", &halfarr[i]);
	}
	vector<ll> ans(n);
	ll lagSum = 0;
	for (int i = 0; i < n/2; ++i) {
		ll rootNewLS = 1000000;
		for (int div : divList[halfarr[i]]) {
			// set div to e
			int ctpt = halfarr[i]/div;
			if ((div + ctpt) % 2 == 1) continue;
			ll a = (div - ctpt) / 2, b = (div + ctpt) / 2;
			if (a <= 0) continue;
			// we have to check
			if (a*a >= lagSum) {
				rootNewLS = min(rootNewLS, b);
			}
		}
		// printf("fixing %d sum %lld\n", 2*i + 1, rootNewLS * rootNewLS);
		if (rootNewLS == 1000000) {
			printf("No\n");
			return 0;
		} else {
			ans[2*i] = rootNewLS * rootNewLS - lagSum - halfarr[i];
			ans[2*i + 1] = halfarr[i];
			lagSum = rootNewLS * rootNewLS;
		}
	}
	printf("Yes\n");
	for (ll x : ans) printf("%lld ", x);
	printf("\n");
	return 0;
}