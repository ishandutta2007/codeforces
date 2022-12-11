#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 200010;

ll solve() {
	int n; ll a, b, c; scanf("%d %lld %lld %lld", &n, &a, &b, &c);
	static char s[NMAX]; scanf("%s", s);
	vector<int> zgaps, ogaps;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			if (i == 0 || s[i-1] == '1') zgaps.push_back(1);
			else ++zgaps.back();
		} else {
			if (i == 0 || s[i-1] == '0') ogaps.push_back(1);
			else ++ogaps.back();
		}
	}
	if (zgaps.size() == 1 && zgaps[0] == n) { // special case: only one zgap
		return (n > 1 ? a : 0);
	}
	if (ogaps.size() == 1 && ogaps[0] == n) { // special case: only one ogap
		return (n > 1 ? b : 0);
	}
	int noncriticals = 0;
	// negative = this zgap cannot do a critical delete
	if (s[0] == '0') {
		//printf("! front is non-critical\n");
		zgaps.front() *= -1;
		++noncriticals;
	}
	if (s[n-1] == '0') {
		//printf("! back is non-critical\n");
		zgaps.back() *= -1;
		++noncriticals;
	}
	for (int i = 0; i < noncriticals; ++i) {
		zgaps.push_back(-n-69); // special sentinel value for the non-critical op3 this gap has
	}
	sort(begin(zgaps), end(zgaps), [&] (int i, int j) {
		return make_pair(i < 0, abs(i)) < make_pair(j < 0, abs(j));	
	});
	reverse(begin(zgaps), end(zgaps));
	int oCountTake = 0;
	for (int v : ogaps) oCountTake += v - 1;
	auto solveWithOnes = [n, a, b, c] (int takeOCount, vector<int> zgaps) {
		// printf("solving with %d free op2s (params %lld %lld %lld)\n", takeOCount, a, b, c);
		ll ans = 0;
		ll cval = ans;
		int ctake = 0;
		while (true) {
			if (ctake == 1) {
				// printf("ctake 1 with %d free op2s\n", takeOCount);
				if (takeOCount == 0) break;
				else {
					--takeOCount;
					cval += b;
					ctake = 0;
				}
			} else {
				// printf("ctake 0 with zgap %d\n", zgaps.back());
				if (zgaps.empty()) break;
				if (zgaps.back() > 0) { // zgap with a critical delete
					if (zgaps.back() > 1) { // normal delete
						cval += a;
						ctake = 1;
					} else { // critical delete
						// if b < c, DO NOT MAKE CRITICAL DELETES
						if (b >= c) {
							// printf("making critical delete\n");
							cval += b - c;
						}
					}
					--zgaps.back();
				} else if (zgaps.back() > -n-69 && zgaps.back() < 0) { // normal delete of lacking zgap
					if (zgaps.back() < -1) {
						cval += a;
						ctake = 1;
						++zgaps.back();
					} else {
						zgaps.pop_back(); // this is already the non-critical op3, we will process this later
					}
				} else if (zgaps.back() == -n-69) { 
					cval -= c;
					ctake = 1;
					zgaps.pop_back();
				} else { // empty zgap; remove and repeat, keeping ctake the same
					zgaps.pop_back();
				}
			}
			// printf("cvalwer currently %d\n", cval);
			ans = max(cval, ans);
		}
		// printf("ans %d\n", ans);
		return ans;
	};
	return max(solveWithOnes(oCountTake, zgaps), (oCountTake > 0 ? b + solveWithOnes(oCountTake - 1, zgaps) : 0));
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		printf("%lld\n", solve());
	}
}