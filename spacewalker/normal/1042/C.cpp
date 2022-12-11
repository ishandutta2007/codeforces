#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	vector<int> pos, neg, zero;
	vector<int> acc, rej;
	for (int i = 0; i < n; ++i) {
		if (arr[i] > 0) pos.push_back(i);
		else if (arr[i] == 0) zero.push_back(i);
		else neg.push_back(i);
	}
	if (pos.size() == 0 && neg.size() <= 1) {
		acc = zero, rej = neg;
	} else {
		sort(neg.begin(), neg.end(), [&arr] (int i, int j) {return arr[i] > arr[j];});
		acc = pos, rej = zero;
		int start = 0;
		if (neg.size() % 2 == 1) rej.push_back(neg[0]), start++;
		for (; start < neg.size(); ++start) {
			acc.push_back(neg[start]);
		}
	}
	for (int i = 0; i + 1 < acc.size(); ++i) {
		printf("1 %d %d\n", acc[i] + 1, acc[i+1] + 1);
	}
	// printf("DONE\n");
	for (int i = 0; i + 1 < rej.size(); ++i) {
		printf("1 %d %d\n", rej[i] + 1, rej[i+1] + 1);
	}
	if (rej.size() > 0) printf("2 %d\n", rej.back() + 1);
	return 0;
}