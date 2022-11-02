#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solve(int l, int r, int s) {
	if(l > s) l = s;
	if(r < s) r = s;
	l = s - l;
	r = r - s;
	return min(l * 2 + r, l + r * 2);
}
int main() {
	int N, A;
	cin >> N >> A;
	vector<int> X(N);
	for(int i = 0; i < N; ++i) cin >> X[i];
	sort(X.begin(), X.end());
	if(N == 1) cout << 0 << endl;
	else {
		cout << min(solve(X[0], X[N - 2], A), solve(X[1], X[N - 1], A)) << endl;
	}
	return 0;
}