#include <bits/stdc++.h>
#define maxn 50
#define states 5000
#define ld long double
using namespace std;
int N, R;

int fast[maxn+1];
int slow[maxn+1];
ld p[maxn+1];
ld dp[maxn+1][states+1];
bool check(ld q) {
	for (int i = 0; i <= R; i++) {
		dp[N][i] = 0.0;
	}
	for (int i = R+1; i <= states; i++) {
		dp[N][i] = q;
	}
	for (int i = N-1; i >= 0; i--) {
		for (int j = 0; j <= states; j++) {
			ld cur = 0.0;
			if (j+fast[i] <= states) {
				cur += p[i]*(fast[i] + dp[i+1][j+fast[i]]);
			}
			else {
				cur += p[i]*(fast[i] + q);
			}
			if (j + slow[i] <= states) {
				cur += (1-p[i])*(slow[i] + dp[i+1][j+slow[i]]);
			}
			else {
				cur += (1-p[i])*(slow[i]+q);
			}
			cur = min(cur, q);
			dp[i][j] = cur;
		}
	}

	if (dp[0][0] >= q) return true;
	return false;
}

int main() {
	cin >> N >> R;
	for (int i = 0; i < N; i++) {
		cin >> fast[i] >> slow[i] >> p[i];
		p[i]/=100.0;
	}

	ld low = 0.0;
	ld high = 100000000000000.0;
	for (int k = 0; k < 700; k++) {
		ld mid = (low+high)/2;
		if (check(mid)) {
			low = mid;
		}
		else high = mid;
	}
	cout << fixed << setprecision(15);
	cout << low << endl;
	// cin >> N;

}