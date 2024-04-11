#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;
constexpr int DIV_BASH_MAX = 15000000;
constexpr ll INF = 1000000000000000000;

set<ll> makeDivList(ll a) {
	// printf("checking divisors of %lld\n", a);
	vector<ll> dl;
	for (int i = 1; i <= DIV_BASH_MAX; ++i) {
		if (a % i == 0) dl.push_back(i);
	}
	set<ll> fans;
	for (ll x : dl) {
		fans.insert(x);
		fans.insert(a/x);
	}
	return fans;
}

ll getSeriesAns(vector<ll> al, ll a, vector<ll> bl, ll b) {
	vector<pair<ll, bool>> keyPoints;
	// printf("check %lld against %lld\n", a, b);
	for (ll x : al) keyPoints.push_back({x, false});
	for (ll x : bl) keyPoints.push_back({x, true});
	ll minA = INF, ans = INF;
	sort(keyPoints.begin(), keyPoints.end());
	for (auto kp : keyPoints) {
		// printf("%lld %d\n", kp.first, kp.second);
		if (!kp.second) minA = a / kp.first;
		else if (b / kp.first >= minA) {
			// printf("valid %lld\n", kp.first);
			ans = min(ans, 2*(kp.first + b / kp.first)); 
			// printf("ans now %lld\n", ans);
		}
	}
	return ans;
}

int main() {
	// printf("yeet\n");
	ll a, b; scanf("%lld %lld", &a, &b);
	set<ll> adiv = makeDivList(a), bdiv = makeDivList(b), apbdiv = makeDivList(a + b);
	vector<ll> alist(adiv.begin(), adiv.end()), blist(bdiv.begin(), bdiv.end()), 
		slist(apbdiv.begin(), apbdiv.end());
	printf("%lld\n", min(getSeriesAns(alist, a, slist, a + b), getSeriesAns(blist, b, slist, a + b)));
	return 0;
}