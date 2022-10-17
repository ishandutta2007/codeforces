#include <bits/stdc++.h>
using namespace std;

int N, K;
int ar[128];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> ar[i];
	}

	int ans = 0;

	for (int i = 0; i < K; i++) {
		map<int, int> appearances;
		// i < N/K
		for (int j = i; j < N; j += K) {
			if (ar[i] != ar[j]) ans++;
			if (ar[i] != ar[j]) ans--;
			appearances[ar[j]] += 1;
		}
		//for (int j = i+K; j < K; j += K){
			ans += min(appearances[1], appearances[2]);
		//}
	}

	cout << ans << endl;
}