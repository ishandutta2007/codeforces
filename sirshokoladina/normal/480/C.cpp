#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);

const int size = 5100;
const int mdl = 1000 * 1000 * 1000 + 7;

int n, a, b, k;

int ans[size][size];
int cum[size];

int main () {
	#ifdef SG
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	cin >> n >> a >> b >> k;

	if (a < b) {
		a = b - a;
		n = b - 1;
	} else {
		a -= b;
		n -= b;
	}
	
	for (int i = 1; i <= n; i++)
		ans[0][i] = 1;
	
	for (int i = 0; i < k; i++) {
		cum[0] = ans[i][0];
		for (int j = 0; j < n; j++) {
			cum[j + 1] = cum[j] + ans[i][j + 1];
			if (cum[j + 1] >= mdl) {
				cum[j + 1] -= mdl;
			}
		}
		
		ans[i + 1][0] = 0;
		for (int j = 1; j <= n; j++) {
			ans[i + 1][j] = (cum[min(n, j + j - 1)] - ans[i][j] + mdl);
			if (ans[i + 1][j] >= mdl) {
				ans[i + 1][j] -= mdl;
			}
		}
		
		//for (int j = 0; j <= n; j++)
		//	cout << i << ' ' << j << ' ' << ans[i][j] << endl;
	}
	
	cout << ans[k][a] << endl;
	
	return 0;
}