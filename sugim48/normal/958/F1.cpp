#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)

int main() {
	int N, M; cin >> N >> M;
	vector<int> a(N);
	rep(i, N) cin >> a[i], a[i]--;
	vector<int> num(M);
	rep(j, M) cin >> num[j];
	int K = 0;
	rep(j, M) K += num[j];
	for (int l = 0; l + K <= N; l++) {
		int r = l + K;
		vector<int> cnt(M);
		for (int i = l; i < r; i++) cnt[a[i]]++;
		if (cnt == num) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}