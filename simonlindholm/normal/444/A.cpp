#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> w(N);
	for (int i = 0; i < N; ++i)
		cin >> w[i];
	double res = 0;
	for (int i = 0; i < M; ++i) {
		int a, b, we;
		cin >> a >> b >> we;
		int ww = w[a-1] + w[b-1];
		res = max(res, ww / (double)we);
	}
	cout << setprecision(10) << fixed << res << endl;
	return 0;
}