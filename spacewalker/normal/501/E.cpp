#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool possibleCenterMap(map<int, int> &occs) {
	int oddElements = 0;
	for (auto e_o : occs) if (e_o.second % 2 == 1) oddElements++;
	return oddElements <= 1;
}

int firstSortable(vector<int> &arr) {
	int n = arr.size();
	int lo = 0, hi = n - 1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
//		printf("attempting to sort 0 to %d\n", mid);
		vector<int> aToFill = arr;
		bool sortable = true;
		map<int, int> elementsToSort;
		for (int i = 0; i <= mid; ++i) {
			++elementsToSort[aToFill[i]];
			aToFill[i] = -1;
		}
		for (int i = n - 1; i >= 0; --i) {
//			printf("detangling pair %d %d\n", aToFill[i], aToFill[n - 1 - i]);
			if (aToFill[i] == -1 && aToFill[n - 1 - i] == -1) continue;
			if (aToFill[i] != -1 && aToFill[n - 1 - i] != -1) {
				if (aToFill[i] == aToFill[n - 1 - i]) continue;
//				printf("%d cancels %d sortability\n", i, mid);
				sortable = false;
				break;
			}
			if (elementsToSort[aToFill[i]] == 0) {
//				printf("%d cannot be filled with element %d\n", i, mid);
				sortable = false;
				break;
			}
//			printf("%d placed in %d\n", aToFill[i], n - 1 - i);
			--elementsToSort[aToFill[i]];
			aToFill[n - 1 - i] = aToFill[i];
		}
//		if (sortable && possibleCenterMap(elementsToSort)) printf("index %d sortable\n", mid);
//		if (!possibleCenterMap(elementsToSort)) printf("remaining %d unsortable\n", mid);
		if (sortable && possibleCenterMap(elementsToSort)) hi = mid;
		else lo = mid + 1;
	}
	return lo;
};

int main() {
	int n; scanf("%d", &n);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	int unequalPair = -1;
	for (int i = 0; i < n; ++i) {
		if (arr[i] != arr[n - i - 1]) {
			unequalPair = i;
			break;
		}
	}
	if (unequalPair == -1) {
		printf("%lld\n", (ll)n * (n - 1) / 2 + n);
		return 0;
	}
	map<int, int> occs;
	for (int i = 0; i < n; ++i) ++occs[arr[i]];
	if (!possibleCenterMap(occs)) {
		printf("0\n");
		return 0;
	}
	vector<int> unpalCore(begin(arr) + unequalPair, end(arr) - unequalPair);
	int forwardCount = unpalCore.size() - firstSortable(unpalCore);
	reverse(begin(unpalCore), end(unpalCore));
//	printf("fc computed\n");
	int backwardCount = unpalCore.size() - firstSortable(unpalCore);
//	printf("fb bc %d %d\n", forwardCount, backwardCount);
	printf("%lld\n", (ll)(unequalPair + 1) * (forwardCount + backwardCount - 2) + (ll)(unequalPair + 1) * (unequalPair + 1));
	return 0;
}