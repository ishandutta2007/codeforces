#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005;

int N, besti;
ll A, max, min, M, ans, a[MaxN], s[MaxN], bestmin, b[MaxN];
std::pair<ll, int> aa[MaxN];

bool good(ll d) {
	int i = std::upper_bound(a, a+N, d) - a;
	ll extra = d * i - (i ? s[i-1] : 0ll);
	return extra <= M;
}

int main()
{
	scanf("%d%lld%lld%lld%lld", &N, &A, &max, &min, &M);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &aa[i].first);
		aa[i].second = i;
	}
	std::sort(aa, aa+N);
	for (int i = 0; i < N; i++) {
		a[i] = aa[i].first;
		s[i] = a[i];
		if (i) s[i] += s[i-1];
	}
	ans = min * a[0];
	for (int i = 0; i < N; i++) if (a[i] == A) ans += max;
	besti = N;
	{
		ll lo = 0, hi = A;
		while (hi-lo > 1) {
			ll mid = (lo+hi) / 2;
			if (good(mid)) lo = mid;
			else hi = mid;
		}
		ll cur = lo*min;
		if (domax(ans, cur)) {
			besti = N;
			bestmin = lo;
		}
	}
	for (int i = N-1; i >= 0; i--) {
		if (i && a[i-1] == A) continue;
		if (A - a[i] > M) break;
		M -= (A - a[i]);
		a[i] = A;
		if (i == 0) {
			if (domax(ans, max * N + A * min)) {
				besti = i;
			}
			break;
		}
		ll lo = 0, hi = A;
		while (hi-lo > 1) {
			ll mid = (lo+hi) / 2;
			if (good(mid)) lo = mid;
			else hi = mid;
		}
		ll cur = (N-i)*max + lo*min;
		if (domax(ans, cur)) {
			besti = i;
			bestmin = lo;
		}
	}
	for (int i = N-1; i >= besti; i--) aa[i].first = A;
	for (int i = 0; i < N; i++) domax(aa[i].first, bestmin);
	for (int i = 0; i < N; i++) b[aa[i].second] = aa[i].first;
	printf("%lld\n", ans);
	for (int i = 0; i < N; i++) printf("%lld%c", b[i], " \n"[i == N-1]);
}