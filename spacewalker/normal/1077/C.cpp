#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;

ll arr[300000];
multiset<ll> elems;

int main() {
	int n; scanf("%d", &n);
	ll totalSum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", arr + i);
		elems.insert(arr[i]);
		totalSum += arr[i];
	}
	vector<int> ans;
	for(int i = 0; i < n; ++i) {
		elems.erase(elems.find(arr[i]));
		if ((totalSum - arr[i]) % 2 == 0 && elems.count((totalSum - arr[i])/2) > 0) {
			// printf("found needed sum %lld\n", totalSum - arr[i]);
			ans.push_back(i);
		}
		elems.insert(arr[i]);
	}
	printf("%lu\n", ans.size());
	for (int x : ans) printf("%d ", x + 1);
	printf("\n");
	return 0;
}