#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> arr(n), type(n);
		for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &type[i]);
		vector<int> typeCount(2);
		for (int x : type) ++typeCount[x];
		if (min(typeCount[0], typeCount[1]) > 0) {
			printf("Yes\n");
			continue;
		}
		bool isSorted = true;
		for (int i = 0; i + 1 < n; ++i) if (arr[i] > arr[i+1]) isSorted = false;
		printf("%s\n", isSorted ? "Yes" : "No");
	}
	return 0;
}