#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> MAGIC = {2, 3, 5, 7, 11};

ll gcd(ll a, ll b) {
	return (b ? gcd(b, a%b) : a);
}

bool powerSubset(ll a, ll b) {
	if (a == 1) return true;
	else {
		ll comfac = gcd(a, b);
		if (comfac == 1) return false;
		else return powerSubset(a/comfac, b);
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int tc = 0; tc < n; ++tc) {
		ll p, q, b; scanf("%lld %lld %lld", &p, &q, &b);
		q /= gcd(p, q);
		// basically if q has no prime factors that are not in b it's finite
		// we're looking if there exists an a such that qa = some power of b
		// printf("check %lld %lld\n", q, b);
		bool infProof = false;
		for (ll torem : MAGIC) {
			if (q % torem == 0) {
				if (b % torem != 0) infProof = true;
				while (q % torem == 0) q /= torem;
				while (b % torem == 0) b /= torem;
			}
			if (infProof) break;
		}
		if (infProof) {
			printf("Infinite\n");
			continue;
		}
		if (powerSubset(q, b)) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}