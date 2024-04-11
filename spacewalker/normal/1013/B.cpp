#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int n, x; scanf("%d %d", &n, &x);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	set<int> arrOrig(arr.begin(), arr.end());
	if (arrOrig.size() < arr.size()) {
		printf("0\n"); return 0;
	}
	multiset<int> arrAnded;
	for (int i = 0; i < n; ++i) arrAnded.insert(arr[i] & x);
	for (int i = 0; i < n; ++i) {
		arrAnded.erase(arrAnded.find(arr[i] & x));
		if (arrAnded.count(arr[i]) > 0) {printf("1\n"); return 0;}
		arrAnded.insert(arr[i] & x);
	}
	set<int> arrAndU(arrAnded.begin(), arrAnded.end());
	if (arrAndU.size() < arr.size()) {printf("2\n"); return 0;}
	printf("-1\n");
	return 0;
}