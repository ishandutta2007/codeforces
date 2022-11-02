#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int Q;
	cin >> Q;
	while (Q--) {
		int N; string S;
		cin >> N >> S;
		int ans = N;
		for (int i = 0; i < N; ++i) {
			for (int j = i; j < N; ++j) {
				if (S[i] == '>' || S[j] == '<') {
					ans = min(ans, N - (j - i + 1));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}