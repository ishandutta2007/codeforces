#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<int> T(N), B(N);
	for (int i = 0; i < N; ++i) {
		cin >> T[i] >> B[i];
	}
	vector<int> p(N);
	for (int i = 0; i < N; ++i) {
		p[i] = i;
	}
	int lim = *max_element(B.begin(), B.end());
	vector<vector<int> > G(lim + 1);
	for (int i = 0; i < N; ++i) {
		G[B[i]].push_back(i);
	}
	priority_queue<int, vector<int>, greater<int> > que;
	long long cursum = 0, ans = 0;
	for (int i = lim; i >= 0; --i) {
		for (int j : G[i]) {
			que.push(T[j]);
			cursum += T[j];
		}
		while (que.size() > K) {
			cursum -= que.top();
			que.pop();
		}
		ans = max(ans, cursum * i);
	}
	cout << ans << endl;
	return 0;
}