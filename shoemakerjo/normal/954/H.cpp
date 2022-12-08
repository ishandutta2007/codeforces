#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 5005
const int mod = 1000000007;

int dp[2][maxn*2]; //space saving dp, might have to be ll
int dpp[2][maxn*2]; //go to parent first
int a[maxn]; //as in the problem
int ans[maxn*2];
int nodes[maxn]; //number of nodes at this level

int n;

int mult(int a, int b) {
	return (a*1LL*b)%mod;
}

void add(int &a, int b) {
	a = (a+b)%mod;
}

int modpow(int base, int p) {
	if (p == 0) return 1;
	if (p & 1) {
		int cur = modpow(base, p-1);
		return mult(cur, base);
	}
	int cur = modpow(base, p/2);
	return mult(cur, cur);
}

int inv(int a) {
	return modpow(a, mod-2); //flt 
}

void print() {
	for (int i = 1; i <= 2*n-2; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a[i];

	}
	a[n] = 0; //just in case (actually will help out)
	int cur = 0, prev = 1; //space saving dp trick
	fill(dp[0], dp[0]+maxn*2, 0);
	fill(dpp[0], dpp[0]+maxn*2, 0);
	fill(ans, ans+maxn*2, 0);

	int nodes[maxn]; //number of nodes here
	nodes[1] = 1;
	for (int i = 2; i <= n; i++) {
		nodes[i] = mult(nodes[i-1], a[i-1]); //go down for each
	}

	dp[cur][0] = 1;
	dpp[cur][0] = 1;
	for (int i = 1; i < n; i++) {
		dp[cur][i] = mult(dp[cur][i-1], a[i]);
		add(ans[i], dp[cur][i]);
	}

	// cout << "starting vals" << endl;
	// print();

	cur = 1;
	prev = 0; //have to add this in
	for (int i = 2; i <= n; i++, swap(cur, prev)) {

		// cout << "running for " << i << endl;
		// cout << "cur and prev:  " << cur << "  " << prev << endl;
		//change the start to this guy
		int pi = inv(a[i-1]); // inverse the number for my parent
		//also have to multiply by one less
		pi = mult(pi, a[i-1]-1);
		for (int j = 0; j <= 2*n-2; j++) {
			dp[cur][j] = 0; //set it all to zero
			dpp[cur][j] = 0;
		}
		dp[cur][0] = 1; //this should always be true
		dpp[cur][0] = 1;
		for (int j = 1; j <= 2*n-2; j++) {
			if (j > 1) add(dpp[cur][j], mult(dp[prev][j-1], pi)); 
			//if j is 1 we would double count the traditional way
			add(dpp[cur][j], dpp[prev][j-1]);
			//go to parent first (then to child or parent)

		}
		int curval = 1;
		for (int j = 1; j <= 2*n-2; j++) {
			if (j+i-1 > n) break; // do not do this
			curval = mult(curval, a[i+j-1]); //go down from this
			add(dp[cur][j], curval);
		}

		for (int j = 1; j <= 2*n-2; j++) {
			// cout << "	vals for " << j << "  " << dp[cur][j] << "  " << dpp[cur][j] << endl;
			add(ans[j], mult(dp[cur][j], nodes[i])); //add these on
			add(ans[j], mult(dpp[cur][j], nodes[i]));
		}

		// cout << endl << "after  " << i << endl;
		// print();
	}
	int iv2 = inv(2);
	for (int i = 1; i <= 2*n-2; i++) {
		ans[i] = mult(ans[i], iv2);
	}
	print();

	// cout << endl << "nodes" << endl;
	// for (int i = 1; i <= n; i++) {
	// 	cout << nodes[i] << " ";
	// }
	// cout << endl;

	cin >> n;
	//NOTE: i think i have to divide by 2

}