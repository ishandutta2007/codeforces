#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
vector<int> transform(int n, vector<int> arr, vector<int> perm) {
	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		res[i] = arr[perm[i]];
	}
	return res;
}
int main() {
	int Q;
	cin >> Q;
	while (Q--) {
		int N, K;
		cin >> N >> K;
		vector<int> A(N), B(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i] >> B[i];
		}
		vector<int> perm(N);
		for (int i = 0; i < N; ++i) {
			perm[i] = i;
		}
		sort(perm.begin(), perm.end(), [&](int i, int j) { return B[i] < B[j]; });
		A = transform(N, A, perm);
		B = transform(N, B, perm);
		int bsum = 0;
		for (int i = 0; i < N; ++i) {
			bsum += B[i] * (K - 1);
		}
		vector<vector<int> > dp(N + 1, vector<int>(K, -inf));
		dp[0][0] = bsum;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < K; ++j) {
				dp[i + 1][j] = dp[i][j];
				if (j >= 1) {
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - 1] + A[i] - B[i] * (K - j));
				}
			}
		}
		int opt = -1, optval = -inf;
		for (int i = 0; i < N; ++i) {
			if (dp[i][K - 1] == -inf) continue;
			int val = dp[i][K - 1];
			int mx = *max_element(A.begin() + i, A.end());
			val += mx;
			if (optval < val) {
				optval = val;
				opt = i;
			}
		}
		vector<int> seq;
		int ptr = K - 1;
		for (int i = opt - 1; i >= 0; --i) {
			if (dp[i][ptr] != dp[i + 1][ptr]) {
				seq.push_back(i);
				--ptr;
			}
		}
		reverse(seq.begin(), seq.end());
		int last = max_element(A.begin() + opt, A.end()) - A.begin();
		vector<int> ans;
		for (int i : seq) {
			ans.push_back(perm[i] + 1);
		}
		for (int i = 0; i < N; ++i) {
			if (!binary_search(seq.begin(), seq.end(), i) && i != last) {
				ans.push_back(perm[i] + 1);
				ans.push_back(-(perm[i] + 1));
			}
		}
		ans.push_back(perm[last] + 1);
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); ++i) {
			if (i) cout << ' ';
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}