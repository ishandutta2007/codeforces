#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define maxn 300010

ll a[maxn];
ll b[maxn];
ll finish[maxn][2]; //finish starting at this index
ll suffix[maxn]; //me and after me
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	//deal in ll's 
	suffix[n-1] = a[n-1] + b[n-1];
	for (int i = n-2; i >= 0; i--) {
		suffix[i] = suffix[i+1] + a[i] + b[i];
	}
	finish[n-1][0] = b[n-1];
	finish[n-1][1] = a[n-1];
	for (int i = n-2; i >= 0; i--) {
		finish[i][0] = finish[i+1][0] + b[i]*(2*n - (2*i+2)+1);
		finish[i][1] = finish[i+1][1] + a[i]*(2*n - (2*i+2)+1);
		finish[i][0] += suffix[i+1];
		finish[i][1] += suffix[i+1];
	}
	int cx = -1;
	int cy = 0;
	ll ans = 0;
	ll cans = 0LL;
	int time = -1;
	while (cx != n) {
		time++;
		cx++;
		ll cur = cans + finish[cx][cy];
		cur += time * suffix[cx];
		ans = max(ans, cur);

		if (cy == 0) {
			cans += time * a[cx];
			time++;
			cans += time * b[cx];
			cy = 1;
		}
		else {
			cans += time * b[cx];
			time++;
			cans += time * a[cx];
			cy = 0;
		}
		ans = max(ans, cans);
	}
	cout << ans << endl;

}