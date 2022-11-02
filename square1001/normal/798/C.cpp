#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int g = A[0];
	for(int i = 1; i < N; ++i) {
		g = __gcd(g, A[i]);
	}
	if(g > 1) {
		cout << "YES" << endl;
		cout << 0 << endl;
	}
	else {
		for(int i = 0; i < N; ++i) {
			A[i] %= 2;
		}
		int ans = 0;
		for(int i = 0; i < N; ++i) {
			if(i < N - 1 && A[i] == 1 && A[i + 1] == 1) {
				++ans;
				A[i] = 0;
				A[i + 1] = 0;
			}
			else if(A[i] == 1) {
				ans += 2;
				A[i] = 0;
			}
		}
		cout << "YES" << endl;
		cout << ans << endl;
	}
	return 0;
}