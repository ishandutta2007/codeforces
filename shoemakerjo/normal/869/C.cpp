#include <bits/stdc++.h>
#define ll long long
using namespace std;
int perms[5001][5001];
int combos[5001][5001];
int main() {
	int a, b, c;
	
	ll mod = 998244353LL;
	for (int i = 0; i <= 5000; i++) {
		perms[i][0] = combos[i][0] = 1;
		perms[i][1] = combos[i][1] = i;
		combos[0][i] = perms[0][i] = 0;
	}
	cin >> a >> b >> c;
	// cout << "here" << endl;
	combos[0][0] = perms[0][0] = 1;
	for (int i = 1; i <= 5000; i++) {
		for (int j =  2; j <= i; j++) {
			ll val = (perms[i-1][j] + 
				perms[i-1][j-1]*(j+0LL))%mod;
			perms[i][j] = (int) val;
			combos[i][j] = (combos[i-1][j] 
				+ combos[i-1][j-1])%mod;
		}
		for (int j = i+1; j <= 5000; j++) {
			perms[i][j] = combos[i][j] = 0;
		}
	}
	// cin >> a >> b >> c;
	vector<int> vals;
	vals.push_back(a);
	vals.push_back(b);
	vals.push_back(c);
	sort(vals.begin(), vals.end());
	ll ans = 1LL;
	for (int i = 0; i < 3; i++) {
		for (int j = i+1; j < 3; j++) {
			int low = vals[i];
			int high = vals[j];
			ll sum = 0LL;
			for (int k = 0; k <= low; k++) {
				sum = (sum+
					(combos[low][k]+0LL)*(0LL+perms[high][k]))%mod;
			}
			ans = (ans*sum)%mod;
		}
	}
	cout << ans << endl;
	// cin >> ans;
}