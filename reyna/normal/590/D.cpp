//In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 159;

#define min(a, b) ((a) > (b)? (b): (a))
#define max(a, b) ((a) > (b)? (a): (b))

int maxdp[N * N][N], mindp[N * N][N];
int a[N];

int main() {
	ios_base::sync_with_stdio(0);
	int n, k, s; cin >> n >> k >> s;
	int sum = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i], sum += i < k? a[i]: 0;
	for (int i = 0; i < N * N; i++)
		for (int j = 1; j < N; j++)
			maxdp[i][j] = -1e9, mindp[i][j] = 1e9;
	s = min(s, n * n);
	for (int i = 0; i < k; i++) {
		for (int work = s; ~work; work--) {
			for (int pick = 1; pick <= i + 1; pick++) {
				if (work >= k - i)
					maxdp[work][pick] = max(maxdp[work][pick], maxdp[work - k + i][pick - 1] + a[i]);
				else
					break;
			}
		}
	}
	for (int i = k; i < n; i++) {
		for (int work = s; ~work; work--) {
			for (int pick = 1; pick <= i - k + 1; pick++) {
				if (work >= i - k)
					mindp[work][pick] = min(mindp[work][pick], mindp[work - i + k][pick - 1] + a[i]);	
				else
					break;
			}
		}
	}
	int res = -1e9;
	for (int pick = 0; pick <= n; pick++) {
		for (int lwork = 0; lwork <= s; lwork++) {
			res = max(res, maxdp[s - lwork][pick] - mindp[lwork][pick]);
		}
	}
	cout << sum - res << endl;
	return 0;
}