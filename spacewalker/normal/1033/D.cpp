#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#define int long long

using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;

// ai is either p^4, p^2 or pq or p^3
// p and q are primes

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

ll perfectSquareRoot(ll x) {
	ll lo = 1, hi = 1500000000;
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		// printf("mid %lld lo %lld hi %lld\n", mid, lo, hi);
		if (mid * mid == x) {
			return mid;
		} else if (mid * mid < x) {
			lo = mid + 1;
		} else {
			hi = mid;
		}
	}
	if (lo * lo == x) return lo;
	else return -1;
}

ll perfectCubeRoot(ll x) {
	ll lo = 1, hi = 1500000;
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		// printf("mid %lld lo %lld hi %lld\n", mid, lo, hi);
		if (mid * mid * mid == x) {
			return mid;
		} else if (mid * mid * mid < x) {
			lo = mid + 1;
		} else {
			hi = mid;
		}
	}
	if (lo * lo * lo == x) return lo;
	else return -1;	
}

 signed main() {
 	ll n; scanf("%lld", &n);
 	vector<ll> arr(n);
 	// printf("here\n");
 	for (int i = 0; i < n; ++i) {
 		scanf("%lld", &arr[i]);
 		// printf("read %lld\n", arr[i]);
 	}
 	set<ll> dis(arr.begin(), arr.end());
 	vector<ll> arrUniq(dis.begin(), dis.end());
 	int k = arrUniq.size();
 	vector<int> type(k); // 1 = p^2, 2 = p^4, 3 = p^3, 4 = pq;
 	vector<map<ll, int>> pfacs(k);
 	// printf("here\n");
 	for (int i = 0; i < k; ++i) {
 		ll att1 = perfectSquareRoot(arrUniq[i]);
 		if (att1 == -1) {
 			ll att2 = perfectCubeRoot(arrUniq[i]);
 			if (att2 == -1) type[i] = 4;
 			else {
 				type[i] = 3;
 				pfacs[i][att2] = 3;
 			}
 		}
 		else {
 			ll att2 = perfectSquareRoot(att1);
 			if (att2 == -1) {
 				type[i] = 1;
 				pfacs[i][att1] = 2;
 			} else {
 				type[i] = 2;
 				pfacs[i][att2] = 4;
 			}
 		}
 		// printf("%lld type %lld\n", arrUniq[i], type[i]);
 	}
 	// printf("here\n");
 	for (int i = 0; i < k; ++i) {
 		if (type[i] != 4) continue;
 		for (int j = 0; j < k; ++j) {
 			if (j == i) continue;
 			ll comdiv = gcd(arrUniq[i], arrUniq[j]);
 			if (type[j] == 4) {
 				if (comdiv > 1) pfacs[i][comdiv] = 1;
 			} else {
 				if (comdiv > 1) pfacs[i][pfacs[j].begin()->first] = 1; 
 			}
 		}
 	}
 	map<ll, ll> knownFacs;
 	for (int i = 0; i < n; ++i) {
 		for (int j = 0; j < k; ++j) {
 			if (arr[i] == arrUniq[j]) {
 				for (auto pPair : pfacs[j]) {
 					knownFacs[pPair.first] += pPair.second;
 				}
 				if (pfacs[j].size() < 2 && type[j] == 4) {
 					for (int x = pfacs[j].size(); x < 2; ++x) {
 						knownFacs[-2*j-10-x] += 1;
 					}
 				}
 			}
 		}
 	}
 	// printf("UNK %lld\n", unkFacs);
 	ll prod = 1;
 	for (auto pPair : knownFacs) {
 		// printf("PAIR %lld %lld\n", pPair.first, pPair.second);
 		prod = (prod * (pPair.second + 1)) % MOD;
 	}
 	printf("%lld\n", prod);
 	return 0;
 }