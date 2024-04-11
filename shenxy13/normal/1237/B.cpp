#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
int arr[100000];
bool inv[100000];
deque<int> merge_sort(int s, int e) {
	if (s == e) return deque<int>(1, arr[s]);
	deque<int> l = merge_sort(s, (s + e) / 2), r = merge_sort((s + e) / 2 + 1, e);
	deque<int> ans;
	while (!l.empty() || !r.empty()) {
		if (l.empty()) {
			ans.push_back(r.front());
			r.pop_front();
		} else if (r.empty()) {
			ans.push_back(l.front());
			inv[l.front()] = true;
			l.pop_front();
		} else if (l.front() < r.front()) {
			ans.push_back(l.front());
			if (r.size() != e - (s + e) / 2) inv[l.front()] = true;
			l.pop_front();
		} else {
			ans.push_back(r.front());
			r.pop_front();
		}
	}
	return ans;
}
int main() {
	fill_n(inv, 100000, false);
	int n, k;
	scanf("%d", &n);
	int pos[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		pos[k - 1] = i;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		arr[i] = pos[k - 1];
	}
	merge_sort(0, n - 1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (inv[i]) ++ans;
	}
	printf("%d", ans);
	return 0;
}