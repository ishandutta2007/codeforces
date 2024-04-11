#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	int N, M, L, S, T;
	cin >> N >> M >> L >> S >> T;
	vector<int> A(M), B(M), C(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i] >> B[i] >> C[i];
	}
	vector<long long> dl(N, 1LL << 61), dr(N, 1LL << 61);
	dl[S] = 0;
	dr[S] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			long long pl = (C[j] == 0 ? 1 : C[j]), pr = (C[j] == 0 ? inf : C[j]);
			dl[B[j]] = min(dl[B[j]], dl[A[j]] + pl);
			dr[B[j]] = min(dr[B[j]], dr[A[j]] + pr);
			dl[A[j]] = min(dl[A[j]], dl[B[j]] + pl);
			dr[A[j]] = min(dr[A[j]], dr[B[j]] + pr);
		}
	}
	if (L < dl[T] || dr[T] < L) {
		cout << "NO\n";
	}
	else {
		dl[T] = L, dr[T] = L;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				long long pl = (C[j] == 0 ? 1 : C[j]), pr = (C[j] == 0 ? inf : C[j]);
				dl[A[j]] = max(dl[A[j]], dl[B[j]] - pr);
				dr[A[j]] = max(dl[A[j]], dr[B[j]] - pl);
				dl[B[j]] = max(dl[B[j]], dl[A[j]] - pr);
				dr[B[j]] = max(dl[B[j]], dr[A[j]] - pl);
			}
		}
		cout << "YES\n";
		for (int i = 0; i < M; ++i) {
			cout << A[i] << ' ' << B[i] << ' ' << (C[i] > 0 ? C[i] : max(abs(dl[B[i]] - dl[A[i]]), 1LL)) << '\n';
		}
	}
	return 0;
}