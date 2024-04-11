#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) cin >> B[i];
	int start = 0;
	for (int i = 0; i < N - 1; ++i) {
		if (B[i] > B[i + 1]) start = i + 1;
	}
	while (start < N && B[start] == 0) ++start;
	priority_queue<int, vector<int>, greater<int> > que;
	for (int i = 0; i < N; ++i) que.push(A[i]);
	int cur = (start == N ? 1 : B[N - 1]);
	bool ok = true;
	for (int i = 0; i < start; ++i) {
		bool rel = false;
		while (!que.empty()) {
			int u = que.top(); que.pop();
			if (u > 0 && u >= cur) {
				cur = u;
				rel = true;
				break;
			}
		}
		if (!rel) {
			ok = false;
			break;
		}
		que.push(B[i]);
	}
	if (ok) cout << start << endl;
	else {
		int ans = N;
		for (int i = 0; i < N; ++i) {
			if (B[i] > 0) ans = max(ans, N + i - B[i] + 2);
		}
		cout << ans << endl;
	}
	return 0;
}