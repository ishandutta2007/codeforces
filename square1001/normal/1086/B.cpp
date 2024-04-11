#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N, S;
	cin >> N >> S;
	vector<vector<int> > G(N);
	for (int i = 0; i < N - 1; ++i) {
		int A, B;
		cin >> A >> B; --A, --B;
		G[A].push_back(B);
		G[B].push_back(A);
	}
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (G[i].size() == 1) ++cnt;
	}
	cout.precision(15);
	cout << double(S) / cnt * 2 << endl;
	return 0;
}