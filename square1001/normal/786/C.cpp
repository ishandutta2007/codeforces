#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i], --A[i];
	vector<int> ans(N + 1);
	vector<int> divs;
	for (int i = 1; i * i <= N; ++i) {
		divs = { 0 };
		vector<int> c(N);
		int diff = 0;
		for (int j = 0; j < N; ++j) {
			if (diff == i && c[A[j]] == 0) {
				for (int k = divs.back(); k < j; ++k) c[A[k]] = 0;
				divs.push_back(j);
				diff = 0;
			}
			if (c[A[j]] == 0) ++diff;
			++c[A[j]];
		}
		ans[i] = divs.size();
	}
	int M = divs.size();
	divs.push_back(N);
	vector<int> kinds(M);
	vector<vector<int> > cx(M, vector<int>(N));
	for (int i = 0; i < M; ++i) {
		for (int j = divs[i]; j < divs[i + 1]; ++j) {
			if (cx[i][A[j]] == 0) ++kinds[i];
			++cx[i][A[j]];
		}
	}
	for (int i = 1; i <= N; ++i) {
		if ((long long)(i) * i <= N) continue;
		for (int j = 0; j < M; ++j) {
			while (divs[j + 1] < N) {
				if (kinds[j] == i && cx[j][A[divs[j + 1]]] == 0) break;
				if (cx[j][A[divs[j + 1]]] == 0) ++kinds[j];
				++cx[j][A[divs[j + 1]]];
				if (j + 1 != M) {
					--cx[j + 1][A[divs[j + 1]]];
					if (cx[j + 1][A[divs[j + 1]]] == 0) --kinds[j + 1];
				}
				++divs[j + 1];
			}
		}
		for (int j = 0; j < M; ++j) {
			if (divs[j] < N) ++ans[i];
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << ans[i];
		cout << (i < N ? ' ' : '\n');
	}
	return 0;
}