#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using LL = long long;

#define MX 500005

int a[2][MX];
int A[MX];
int B[MX];
int valA[MX], valB[MX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	int Tc;
	for (cin >> Tc; Tc--; ) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> a[0][i], a[0][i] ++;
		for (int i = 0; i < n; i ++) cin >> a[1][i], a[1][i] ++;
		a[0][0] = 0;
		valA[n] = valB[n] = 0;
		A[n] = B[n] = 0;
		for (int i = n - 1; i >= 0; i --) {
			if (i == n - 1) {
				A[i] = a[0][i];
				B[i] = a[1][i];
				valA[i] = a[0][i];
				valB[i] = a[1][i];
			}
			else {
				A[i] = max(A[i + 1], a[0][i] + n - i - 1);
				B[i] = max(B[i + 1], a[1][i] + n - i - 1);
				valA[i] = max(valA[i + 1] + 1, a[0][i]);
				valB[i] = max(valB[i + 1] + 1, a[1][i]);
			}
		}
		int st = 0;
		int rlt = INT_MAX;
		for (int i = 0; i < n; i ++) {
			if (i % 2 == 0) {
				int val = max(st + n - i - 1, A[i + 1]);
				val = max(val + 1, a[1][n - 1]);
				val = max(val + n - i - 1, valB[i]);
				st = max(st + 1, a[1][i]);
				st = max(st + 1, a[1][i + 1]);
				rlt = min(rlt, val);
			}
			else {
				int val = max(st + n - i - 1, B[i + 1]);
				val = max(val + 1, a[0][n - 1]);
				val = max(val + n - i - 1, valA[i]);
				st = max(st + 1, a[0][i]);
				st = max(st + 1, a[0][i + 1]);
				rlt = min(rlt, val);
			}
		}
		cout << rlt << endl;
	}
	return 0;
}