#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int NMAX = 200010;
char bstr[NMAX];

constexpr int MAGIC = 90000000;
constexpr int OFFSET = 200000;
int psums[MAGIC];

ll countZeroSubarrays(int k) {
	int n = strlen(bstr);
	psums[OFFSET]++;
	vector<int> toZero{OFFSET};
	ll ans = 0, csum = 0;
	for (int i = 0; i < n; ++i) {
		csum += (bstr[i] == '1' ? (k - 1) : -1);
		ans += psums[csum + OFFSET];
		psums[csum + OFFSET]++;
		toZero.push_back(csum + OFFSET);
	}
	for (int x : toZero) psums[x] = 0;
	return ans;
}

ll lastMult(ll x, ll mod, ll k) {
	if (x < k) return k - mod;
	return (x - k) / mod * mod + k;
}

ll countAppear(ll a, ll b, ll mod, ll k) {
	if (b < k) return 0;
	ll basis1 = (b - k) / mod;
	if (a < k) a = k;
	ll basis2 = (a - k) / mod + ((a - k) % mod == 0 ? 0 : 1);
//	printf("b1 b2 %lld %lld\n", basis1, basis2);
	return max(0LL, basis1 - basis2 + 1);
}

ll countNonBanned(ll maxA, ll maxB, ll s, ll mod, ll k) {
	if (s < 0) s = -1;
	if (maxB >= maxA) swap(maxA, maxB);
	if (s >= maxA + maxB) return 0;
	ll ans = 0;
	// count the upper-right triangle
	ll urStart = lastMult(maxA + maxB, mod, k);
	ll urUntil = max(1LL, s - maxA + 1);
//	ll urIterc = max(0LL, (urStart - maxA - urUntil + 1) / mod);
	ll urIterc = max(0LL, countAppear(urUntil, urStart - maxA, mod, ((k - maxA) % mod + mod) % mod));
//	printf("%lld %lld %lld\n", urStart, urUntil, urIterc);
	ans += urIterc * (2 * (maxA + maxB - urStart + 1) + (urIterc - 1) * mod) / 2;
//	printf("ur %lld\n", ans);
	if (s < maxA) {
//		printf("mp computed\n");
		// count the middle parallelogram
		ll mpStart = lastMult(maxA, mod, k);
		ll urUntil = max(maxB, s + 1);
//		printf("%lld %lld\n", mpStart, urUntil);
		ans += (maxB + 1) * countAppear(urUntil, mpStart, mod, k);
	}
//	printf("ur mp %lld\n", ans);
	if (s < maxB && maxB > 0) {
//		printf("ll computed\n");
	// count the lower-left triangle
		ll llStart = lastMult(maxB - 1, mod, k);
		ll llUntil = max(s + 1, 0LL);
//		ll llIterc = max(0LL, (llStart - llUntil + 1) / mod);
		ll llIterc = max(0LL, countAppear(llUntil, llStart, mod, k));
//		printf("%lld %lld %lld\n", llStart, llUntil, llIterc);
		ans += llIterc * (2 * (llStart + 1) - (llIterc - 1) * mod) / 2;
	}
//	printf("cnb(%lld %lld %lld %lld %lld) = %lld\n", maxA, maxB, s, mod, k, ans);
	return ans;
}

int main() {
	scanf("%s", bstr);
	int n = strlen(bstr);
	ll ans = 0;
	for (int k = 1; k <= sqrt(n); ++k) {
		ll cCount = countZeroSubarrays(k);
		ans += cCount;
//		printf("%lld on k = %d\n", cCount, k);
	}
//	printf("done with first half\n");
	vector<int> onePos{-1};
	for (int i = 0; i < n; ++i) if (bstr[i] == '1') onePos.push_back(i);
	onePos.push_back(n);
	for (int c = 1; c < sqrt(n); ++c) {
//		printf("check c %d\n", c);
		for (int st = 1; st + c < onePos.size(); ++st) {
			// at best, this range goes from st to st + c - 1
			ll aSideExtra = onePos[st] - onePos[st - 1] - 1;
			ll bSideExtra = onePos[st + c] - onePos[st + c - 1] - 1;
			ll minLength = onePos[st + c - 1] - onePos[st] + 1;
			ll banIfLEQ = c * int(sqrt(n));
			ll cCount = countNonBanned(aSideExtra, bSideExtra, banIfLEQ - minLength, c, ((-minLength % c) + c) % c);
//			printf("banLength %lld\n", banIfLEQ);
//			printf("ans %d %d = %lld\n", onePos[st], onePos[st+c-1], cCount);
			ans += cCount;
		}
	}
	printf("%lld\n", ans);
	return 0;
}