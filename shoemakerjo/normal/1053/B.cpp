#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 300010
#define pii pair<int, int>

int n;
int obit[maxn];
int myleft[maxn];
int myright[maxn];
// int mods[maxn][65];
int numseen[2*65];
int faft[maxn][65];
// vector<pii> activate[maxn];
int curact[65][2*65];

int goward[maxn][2*65];
ll evenact[maxn];
ll oddact[maxn];
ll pref[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	ll cur;
	for (int i = 1; i <= n; i++) {
		obit[i] = 0;
		cin >> cur;
		while (cur > 0) {
			if (cur % 2) obit[i]++;
			cur /= 2LL;
		}
		// cout << i << " : " << obit[i] << endl;

	}
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < 65; j++) faft[i][j] = faft[i+1][j];
		faft[i][obit[i]] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		int osum = 0;
		int csum = 0;
		for (int j = i; j <= n && j <= i+128; j++) {
			osum = csum;
			if (osum >= 128) break;
			csum += obit[j];
			for (int k = osum+1; k <= csum && k <= 128; k++) {
				goward[i][k] = j;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		pref[i] = obit[i] + pref[i-1];
	}
	// cout << "here 3 " << endl;

	// int csum = 0;
	// for (int i = 1; i <= n; i++) {
	// 	csum += obit[i];
	// 	for (int j = 1; j < 65; j++) {
	// 		mods[i][j] = (csum)%(2*j);
	// 	}
	// }
	// cout << "here 4 " << endl;
	ll ans = 0LL;
	int sp;
	for (int i = 1; i <= n; i++) {
		int cend = n;
		for (int j = 64; j > 0; j--) {
			if (faft[i][j] == 0) continue;
			if (faft[i][j] > cend) continue;
			sp = faft[i][j];


			int firstposs = goward[i][2*j];
			if (firstposs > cend || firstposs == 0) {
				cend = sp-1;
				continue;
			}
			firstposs = max(firstposs, sp);
			if (pref[i-1]%2) {
				oddact[firstposs] += 1LL;
				oddact[cend+1] -= 1LL;
			}
			else {
				evenact[firstposs] += 1LL;
				evenact[cend+1] -= 1LL; 
			}


			//go from sp to cend (inclusive)
			//count number equivalent to mine in the mod
			// activate[sp].push_back(pii(mods[i-1][j], j));
			// activate[cend+1].push_back(pii(0-mods[i-1][j]-1, j));

			// cout << i << ": doing: " << j << " " << 
			// 	"from " << firstposs << " to " << cend << endl;

			//need sum at least 2 * j + pref[i-1]
			cend = sp-1;
			if (cend < i) break;
		}
	}
	ll numodd = 0LL;
	ll numeven = 0LL;

	for (int i = 1; i <= n; i++) {
		numodd += oddact[i];
		numeven += evenact[i];
		if (pref[i]%2) ans += numodd;
		else ans += numeven;
		// cout << "after " << i << " : " << ans << endl;
	}


	cout << ans << endl;

}