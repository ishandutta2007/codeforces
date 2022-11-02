#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<pair<int, int> > A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i].first >> A[i].second;
		--A[i].first, --A[i].second;
		if (A[i].first > A[i].second) swap(A[i].first, A[i].second);
	}
	sort(A.begin(), A.end());
	bool flag = false;
	for (int i = 1; i < N; ++i) {
		if (N % i == 0) {
			vector<pair<int, int> > B(M);
			for (int j = 0; j < M; ++j) {
				B[j].first = (A[j].first + i) % N;
				B[j].second = (A[j].second + i) % N;
				if (B[j].first > B[j].second) swap(B[j].first, B[j].second);
			}
			sort(B.begin(), B.end());
			if (A == B) {
				flag = true;
			}
		}
	}
	cout << (flag ? "Yes" : "No") << endl;
	return 0;
}