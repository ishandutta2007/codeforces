#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<int> getMaxPart(int n, ll k) {
	vector<int> ans;
	ll cSum = 0;
	if (k == 0) return ans;
	for (int i = n; i >= 1; --i) {
		if (cSum + i <= k) {
			ans.push_back(i);
			cSum += i;
		} else {
			break;
		}
	}
	if (ans.size() < n && k - cSum > 0 && k - cSum <= n) ans.push_back(k - cSum);
	return ans;
}

int main() {
	ll a, b; scanf("%lld %lld", &a, &b);
	bool swapped = false;
	if (a > b) swap(a, b), swapped = true;
	ll lo = 0; ll hi = 1000000;
	while (lo < hi) {
		// nnnnyyyyyyyy
		ll mid = (lo + hi) / 2;
		// printf("testing %lld\n", mid);
		vector<int> day1 = getMaxPart(mid, a);
		// printf("here\n");
		ll cSum = 0;
		for (int x : day1) cSum += x;
		if ((mid)*(mid+1)/2 - cSum <= b) {
			lo = mid + 1;
		} else {
			hi = mid;
		}
	}
	vector<int> day1 = getMaxPart(lo-1, a);
	vector<bool> isRead(lo-1);
	vector<int> day2;
	for (int x : day1) isRead[x-1] = true;
	for (int i = 0; i < lo-1; ++i) {
		if (!isRead[i]) day2.push_back(i+1);
	}
	if (swapped) swap(day1, day2);
	printf("%lu\n", day1.size());
	for (int x : day1) {printf("%d ", x);}
	printf("\n");
	printf("%lu\n", day2.size());
	for (int x : day2) {printf("%d ", x);}
	printf("\n");
	return 0;
}