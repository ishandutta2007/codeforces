#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2012345678;
int solve(int N, vector<int> A, vector<int> D, int M) {
	vector<int> v;
	for(int i = 0; i < N; ++i) {
		if(A[i] >= M) {
			v.push_back(D[i]);
		}
	}
	sort(v.begin(), v.end());
	if(v.size() < M) return inf;
	int ans = 0;
	for(int i = 0; i < M; ++i) {
		ans += v[i];
	}
	return ans;
}
int main() {
	int N, T;
	cin >> N >> T;
	vector<int> A(N), D(N);
	for(int i = 0; i < N; ++i) {
		cin >> A[i] >> D[i];
	}
	int L = 0, R = N + 1;
	while(R - L > 1) {
		int M = (L + R) >> 1;
		if(solve(N, A, D, M) <= T) L = M;
		else R = M;
	}
	cout << L << endl;
	cout << L << endl;
	vector<int> ans;
	for(int i = 0; i < N; ++i) {
		if(A[i] >= L) ans.push_back(i);
	}
	sort(ans.begin(), ans.end(), [&](int i, int j) { return D[i] < D[j]; });
	for(int i = 0; i < L; ++i) {
		if(i) cout << ' ';
		cout << ans[i] + 1;
	}
	cout << endl;
	return 0;
}