#include <bits/stdc++.h>

using namespace std;

const int MX = 500005;

int Tc, N, A[MX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("I", "r", stdin);
	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j;
	for (cin >> Tc; Tc--; ) {
		cin >> N;
		for (i = 0; i < N; i++) cin >> A[i];
		int sum = 0;
		for (i = 0; i < N; i++) sum += A[i];
		int rlt;
		if (sum == N) rlt = 0;
		else if (sum < N) rlt = 1;
		else rlt = sum - N;
		cout << rlt << '\n';
	}

	return 0;

}