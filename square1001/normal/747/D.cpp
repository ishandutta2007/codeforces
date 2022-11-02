#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	int cur = 0, lasts = 0;
	vector<int> comp;
	for (int i = 0; i < N; ++i) {
		if (cur == 0 && A[i] < 0) {
			comp.push_back(lasts);
			lasts = 0;
			cur = 1;
		}
		else if (cur == 1 && A[i] >= 0) {
			comp.push_back(lasts);
			lasts = 0;
			cur = 0;
		}
		++lasts;
	}
	comp.push_back(lasts);
	vector<int> cs;
	for (int i = 1; i < comp.size(); ++i) {
		if (i % 2 == 1) K -= comp[i];
		else if (i + 1 != comp.size()) cs.push_back(comp[i]);
	}
	if (K < 0) {
		cout << -1 << endl;
	}
	else if (comp.size() == 1) {
		cout << 0 << endl;
	}
	else {
		sort(cs.begin(), cs.end());
		int current = int(comp.size()) - 1, ans = current;
		if (comp.size() % 2 == 1 && K >= comp.back()) ans = min(ans, current - 1);
		for (int i = 0; i < cs.size(); ++i) {
			K -= cs[i];
			current -= 2;
			if (K >= 0) ans = min(ans, current);
			if (comp.size() % 2 == 1 && K >= comp.back()) ans = min(ans, current - 1);
		}
		cout << ans << endl;
	}
	return 0;
}