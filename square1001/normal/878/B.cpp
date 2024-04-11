#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N, K, M;
	cin >> N >> K >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	vector<pair<int, int> > seq;
	int pre = 0;
	for (int i = 1; i <= N; ++i) {
		if (i == N || A[i] != A[i - 1]) {
			int len = (i - pre) % K;
			if (!seq.empty() && seq.back().first == A[i - 1]) {
				seq.back().second += i - pre;
			}
			else {
				seq.push_back(make_pair(A[i - 1], len));
			}
			seq.back().second %= K;
			if (seq.back().second == 0) seq.pop_back();
			pre = i;
		}
	}
	long long sum = 0; bool reduce = false;
	int L = 0, R = seq.size();
	while (R - L >= 2) {
		if (seq[L].first == seq[R - 1].first) {
			int cl = seq[L].second;
			int cr = seq[R - 1].second;
			if (cl + cr < K) break;
			else if (cl + cr == K) sum += cl + cr, ++L, --R;
			else { reduce = true; break; }
		}
		else break;
	}
	if (R - L >= 2) {
		long long mid = 0;
		for (int i = L; i < R; ++i) {
			mid += seq[i].second;
		}
		if (reduce) mid -= K;
		cout << mid * M + sum + (reduce ? K : 0) << endl;
	}
	else {
		if (L == R) cout << 0 << endl;
		else cout << ((long long)(seq[L].second) * M % K == 0 ? 0 : sum + (long long)(seq[L].second) * M % K) << endl;
	}
	return 0;
}