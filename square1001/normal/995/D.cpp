#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<int> C(1 << N);
	long long sumc = 0;
	for (int i = 0; i < 1 << N; ++i) {
		cin >> C[i];
		sumc += C[i];
	}
	cout.precision(15);
	for (int i = 0; i <= Q; ++i) {
		cout << double(sumc) / (1 << N) << '\n';
		if (i != Q) {
			int z, g;
			cin >> z >> g;
			sumc -= C[z];
			C[z] = g;
			sumc += C[z];
		}
	}
	return 0;
}