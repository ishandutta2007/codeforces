#include <bits/stdc++.h>

using namespace std;
#define maxn 52
#define ll long long
#define pii pair<int, int>
int a[maxn];
int b[maxn];
const int k5 = 5000;
int n;
ll dp[maxn][maxn][k5+5];

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
	vector<pii> tasks;
	tasks.push_back(pii(1234567890, -1));
	tasks.push_back(pii(-1234567890, -1));
	int st = 1;
	for (int i = 0; i < n; i++) {
		tasks.push_back(pii(a[i], b[i]));
	}
	sort(tasks.begin(), tasks.end());
	reverse(tasks.begin(), tasks.end());
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			fill(dp[i][j], dp[i][j]+k5+5, 123456783456789);
		}
	}

	dp[0][0][0] = 0;

	for (int i = 1; i <= n; i++) {
		// cout << i << ": " << i << endl;
		if (tasks[i].first != tasks[i+1].first) {
			ll power = tasks[i].first;
			vector<int> proc;
			for (int j = st;  j <= i; j++) {
				proc.push_back(tasks[j].second);
			}
			//look at index st-1

			sort(proc.begin(), proc.end());
			reverse(proc.begin(), proc.end());
			int tot = i-st+1; //how many we have
			// cout << "   " << st << endl;
			ll psum = 0LL;
			int procsum = 0;
			for (int taker1 = 0; taker1 <= tot; taker1++) {
				int r2 = tot-taker1;

				// cout << "here  " << procsum << endl;

				for (int j = 0; j <= n; j++) {
					for (int k = 0; k <= k5;  k++) {

						// cout << "this: " << procsum << endl;

						//do the dp transition here
						if (k - procsum < 0) continue;
						//end with j open
						//thus there are j + r2 - taker1 before
						if (j + r2 - taker1 < 0
						 || j + r2 - taker1 > n) continue;
						if (j + r2 - taker1 - r2 < 0) continue;

						// assert(procsum >= 0);
						// assert(st-1 >= 0);
						// assert(k - procsum <= k5);
						// assert(k - procsum >= 0);
						// assert(j+r2 - taker1 >= 0);
						// assert(j + r2 - taker1 <= n);

						dp[i][j][k] = min(dp[i][j][k],
							dp[st-1][j+r2-taker1][k-procsum] + 
							psum);

					}
				}
				// cout << "here2" << endl;
				if (taker1 < tot) {
					// cout << "this" << endl;
					procsum += proc[taker1];
				}
				psum += power;
			}

			st = i+1;
		}
		else continue;
	}
	// cout << "down low " << endl;
	ll ans = 1234567890123457LL;
	// double da = 1234567890.0;
	int bo = -1;
	for (int i = 0; i <= n; i++) {
		// cout << "iteration i: "<< i << endl;
		for (int j = 1; j <= k5; j++) {
			// da = min(da, dp[n][i][j] * 1000.0 / (j));
			if ((dp[n][i][j] * 1000LL + j-1) / j < ans) {
				bo = i;
			}
			ans = min(ans, (dp[n][i][j] * 1000LL + j-1) / j);
		}
	}
	// cout << da << endl;
	// cout << "bo:  " << bo << endl;
	cout << ans << endl;
	cin >> ans;

}