#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) cin >> A[i], --A[i];
	for (int i = 0; i < N; ++i) cin >> B[i], --B[i];
	vector<vector<int> > ans;
	for (int i = 0; i < N; ++i) {
		int tx = find(A.begin(), A.end(), i) - A.begin();
		int ty = find(B.begin(), B.end(), i) - B.begin();
		if (tx != i || ty != i) {
			ans.push_back({ i, ty, tx, i });
			swap(A[i], A[tx]);
			swap(B[i], B[ty]);
		}
	}
	cout << ans.size() << endl;
	for (vector<int> i : ans) {
		cout << i[0] + 1 << ' ' << i[1] + 1 << ' ' << i[2] + 1 << ' ' << i[3] + 1 << endl;
	}
	return 0;
}