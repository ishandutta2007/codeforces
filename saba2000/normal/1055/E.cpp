#include<bits/stdc++.h>
using namespace std;
int n, mx[1509],A[1509],dp[1509][1509],k,s,m, B[1509];
int check(int X) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = i;
		}
	}
	for(int i = 0; i < n; i++){
        if(A[i] <= X) B[i] = 1;
        else B[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
            dp[i+1][j] =min(dp[i+1][j], dp[i][j] + B[i]);
		}
		if (mx[i] > i) {
			for (int j = 0; j < m; j++) {
                dp[mx[i]][j+1] = min(dp[mx[i]][j+1], dp[i][j]);
			}
		}
	}
	int ss = 0;
	for (int i = 0; i < n; i++) {
		ss += B[i];
	}
	return ss - dp[n][m] >= k;
}

int main() {
	cin >> n >> s >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= s; i++) {
		int l, r;
		cin >> l >> r;
		mx[l-1] = max(mx[l-1], r);
	}
	for (int l = 0; l < n; l++) {
		mx[l] = max(mx[l-1], mx[l]);
	}
	int lo = 1, hi = 1e9+1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (check(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	if(lo < 1e9 + 1)
        cout << lo << endl;
    else cout<<-1<<endl;
}