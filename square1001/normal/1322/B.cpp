#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solve(int N, vector<int> A) {
	sort(A.begin(), A.end());
	int mx = *max_element(A.begin(), A.end());
	int bit = 0;
	while ((1 << bit) <= mx) ++bit;
	int ans = 0;
	for (int i = bit; i >= 0; --i) {
		int mid = lower_bound(A.begin(), A.end(), 1 << i) - A.begin();
		int cnt = 0;
		for (int j = mid; j < N; ++j) {
			A[j] -= 1 << i;
			++cnt;
		}
		vector<int> B(N);
		merge(A.begin(), A.begin() + mid, A.begin() + mid, A.end(), B.begin());
		A = B;
		int ptr = N;
		long long sub = 1LL * cnt * (N - cnt);
		for (int j = 0; j < N; ++j) {
			while (ptr != 0 && A[ptr - 1] + A[j] >= (1 << i)) --ptr;
			sub += min(N - ptr, N - j - 1);
		}
		if (sub & 1) ans += 1 << i;
	}
	return ans;
}
int solve_easy(int N, vector<int> A) {
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			ans ^= A[i] + A[j];
		}
	}
	return ans;
}
#include <random>
#include <string>
mt19937 mt(2003071849);
int rand_rng(int l, int r) {
	uniform_int_distribution<int> p(l, r - 1);
	return p(mt);
}
string to_string(vector<int> A) {
	string res = "[";
	for (int i = 0; i < A.size(); ++i) {
		if (i) res += ", ";
		res += to_string(A[i]);
	}
	return res;
}
void random_gen() {
	const int samples = 10000;
	int N = 10, lim = 128;
	for (int i = 1; i <= samples; ++i) {
		vector<int> A(N);
		for (int j = 0; j < N; ++j) {
			A[j] = rand_rng(0, lim);
		}
		int res1 = solve(N, A);
		int res2 = solve_easy(N, A);
		if (res1 != res2) {
			cout << "Case #" << i << ":" << endl;
			cout << "N = " << N << " / A = " << to_string(A) << endl;
			cout << "Returns: " << res1 << endl;
			cout << "Answer: " << res2 << endl;
		}
	}
}
int main() {
	// random_gen();
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int res = solve(N, A);
	cout << res << endl;
	return 0;
}