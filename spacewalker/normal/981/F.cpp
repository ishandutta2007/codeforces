#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n; ll L;
vector<int> brides, grooms;
vector<ll> staticPoints;
vector<pair<ll, int>> activeRanges;

ll refPosKey(int i, vector<int> &arr) {
	if (i >= n) return refPosKey(i - n, arr) + L;
	else return arr[i];
}

struct Monoqueue {
	deque<pair<ll, int>> dq;
	int keepLeft, keepRight;
	vector<ll> arr;
	Monoqueue(int n) : dq(), keepLeft(0), keepRight(0), arr(n) {}
	void initiate() {
		dq.emplace_back(arr[0], 0);
	}
	void removeLeft() {
		if (dq.front().second == keepLeft) dq.pop_front();
		++keepLeft;
	}
	void addRight() {
		++keepRight;
		while (!dq.empty() && dq.back().first >= arr[keepRight]) dq.pop_back();
		dq.emplace_back(arr[keepRight], keepRight);
	}
	ll getMin(int i, int j) {
		while (keepRight < j) addRight();
		while (keepLeft < i) removeLeft();
		return dq.front().first;
	}
};

bool isPossible(ll dist) {
	// keep a 0...2L - 1 copy of the circle
	// brides are ranges, grooms are points
	vector<int> rangeCenters; // these refer back to the {brides, grooms} arrays
	for (int x = 0; x < 2; ++x) {
		for (int i = 0; i < n; ++i) {
			if (brides[i] - dist + x * L >= 0 && brides[i] + dist + x * L < 2 * L) {
				rangeCenters.push_back(i + n * x);
			}
		}
	}
	vector<int> ptsBehind(rangeCenters.size()), ptsForward(rangeCenters.size());
	for (int i = 0; i < rangeCenters.size(); ++i) {
		int newForward = distance(begin(staticPoints), upper_bound(begin(staticPoints), end(staticPoints),
					refPosKey(rangeCenters[i], brides) + dist));
		int newBackward = distance(begin(staticPoints), lower_bound(begin(staticPoints), end(staticPoints),
					refPosKey(rangeCenters[i], brides) - dist));
		ptsForward[i] = newForward;
		ptsBehind[i] = newBackward;
	}
	// first check if all points are covered
	// then compute if the condition is satisfied for all the intervals
	vector<bool> intervalRep(n);
	Monoqueue cfing(rangeCenters.size());
	for (int i = 0; i < rangeCenters.size(); ++i) cfing.arr[i] = ptsForward[i] - i;
	vector<int> compressor(2 * n);
	for (int i = 0; i < rangeCenters.size(); ++i) compressor[rangeCenters[i]] = i;
	cfing.initiate();
	for (int i = 0; i < rangeCenters.size(); ++i) {
		int px = rangeCenters[i];
		ll pil = refPosKey(px, brides);
		if (px >= n) px -= n;
		if (intervalRep[px]) continue;
		intervalRep[px] = true;
		int checkUntil = prev(upper_bound(begin(activeRanges), end(activeRanges), make_pair(pil + L - 2*dist - 1, -1)))->second;
		checkUntil = compressor[checkUntil];
		if (cfing.getMin(i, checkUntil) < ptsBehind[i] - i + 1) return false;
	}
	return true;
}

ll circleDistance(ll x, ll y) {
	ll base = (y - x + L) % L;
	return min(base, L - base);
}

int main() {
	scanf("%d %lld", &n, &L);
	brides = grooms = vector<int>(n);
	for (int i = 0; i < n; ++i) scanf("%d", &grooms[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &brides[i]);
	sort(begin(brides), end(brides));
	sort(begin(grooms), end(grooms));
	set<int> bridePos(begin(brides), end(brides));
	ll lo = 0, hi = L / 2;
	for (int g : grooms) {
		ll nearestBride = 1000000000;
		auto nextBride = bridePos.lower_bound(g);
		if (nextBride != bridePos.end()) nearestBride = min(nearestBride, circleDistance(g, *nextBride));
		if (nextBride != bridePos.begin()) nearestBride = min(nearestBride, circleDistance(g, *prev(nextBride, 1)));
		nearestBride = min(nearestBride, min(circleDistance(g, brides[0]), circleDistance(g, brides[n-1])));
		lo = max(lo, nearestBride);
	}
	for (int x = 0; x < 2; ++x) {
		for (int i = 0; i < n; ++i) {
			activeRanges.emplace_back(brides[i] + x * L, i + x * n);
		}
	}
	staticPoints = vector<ll>(2 * n);
	for (int i = 0; i < n; ++i) {
		staticPoints[i] = grooms[i];
		staticPoints[i + n] = grooms[i] + L;
	}
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
//		printf("checking %lld\n", mid);
		if (isPossible(mid)) {
//			printf("%lld possible\n", mid);
			hi = mid;
		} else {
//			printf("%lld impossible\n", mid);
			lo = mid + 1;
		}
//		printf("ITER\n");
	}
	printf("%lld\n", lo);
	return 0;
}