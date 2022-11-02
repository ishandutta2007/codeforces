#include <queue>
#include <vector>
#include <iostream>
using namespace std;
const long long limit = 2000000000019;
int main() {
	int N, K;
	cin >> N >> K;
	vector<long long> A(N), B(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) cin >> B[i];
	long long L = -1, R = limit * 1.2;
	while (R - L > 1) {
		if (L >= limit) break;
		long long M = (L + R) >> 1;
		vector<long long> TLE(N), charged(N);
		priority_queue<pair<long long, int> > que;
		for (int i = 0; i < N; ++i) {
			TLE[i] = A[i] / B[i];
			if (TLE[i] < K) que.push(make_pair(-TLE[i], i));
		}
		bool ok = true;
		for (int i = 0; i < K && !que.empty(); ++i) {
			pair<long long, int> u = que.top(); que.pop();
			if (i > -u.first) {
				ok = false;
				break;
			}
			charged[u.second] += M;
			long long rem = A[u.second] - B[u.second] * (i + 1) + charged[u.second];
			if (i != K - 1 && rem < 0) {
				ok = false;
				break;
			}
			TLE[u.second] = (i + 1) + rem / B[u.second];
			if (TLE[u.second] < K) que.push(make_pair(-TLE[u.second], u.second));
		}
		if (ok) R = M;
		else L = M;
	}
	cout << (R >= limit ? -1 : R) << endl;
	return 0;
}