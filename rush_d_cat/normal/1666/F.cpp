#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

const int N = 5002;
int n, a[N];
ll dp[N][N];
void add(ll&x, ll y){
	x+=y; x%=mod;
}

ll fac[N], inv[N];
ll mpow(ll a, ll x) {
	if (x == 0) return 1;
	ll t = mpow(a, x>>1);
	if (x%2==0) return t * t % mod;
	return t * t % mod * a % mod;
}
ll c(int x, int y) {
	if (x < 0 || y < 0 || y > x) return 0;
	return fac[x] * inv[y] % mod * inv[x-y] % mod;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	
	fac[0] = 1;
	for (int i = 1; i < N; i ++) 
		fac[i] = fac[i-1] * i % mod;

	for (int i = 0; i < N; i ++) 
		inv[i] = mpow(fac[i], mod - 2);

	int t; cin >> t;
	while (t --) {
		cin >> n;
		for (int i = 0; i <= n; i ++) for (int j = 0; j <= n; j ++) dp[i][j] = 0;
		int cp_n = n;

		
		for (int i = 1; i <= n; i ++)
			cin >> a[i]; 

		reverse(a + 1, a + 1 + n);
		vector<int> v;
		
		for (int i = 1, j = 1; i <= n; i = j) {
			while (j <= n && a[i] == a[j]) j ++;
			v.push_back(j - i);
		}
		n = v.size();
		for (int i = 1; i <= n; i ++) a[i] = v[i-1];
		if (a[1] >= 2) {
			cout << 0 << "\n"; continue;
		}
		dp[1][1] = 1;
		auto free_pos = [&](int x, int y) {
			return y - (y==cp_n/2?0:1) - (x - y);
		};

		int tot = 0;
		for (int i = 1; i < n; i ++) {
			tot += a[i];
			for (int j = 1; j <= min(i, cp_n / 2); j ++) {
				if (dp[i][j] == 0) continue;

				//cout << i << " " << j << " " << dp[i][j] << "\n";
	
				//cout << "add1 " << i+1 << " " << j << " " << dp[i][j] * c(free_pos(tot, j), a[i+1])<< "\n";
				//cout << "free " << tot << " " << j << " " << free_pos(tot, j) << "\n";
				add(dp[i+1][j], dp[i][j] * c(free_pos(tot, j), a[i+1]));
				
				//cout << "free " << tot + 1 << " " << j+1 << " " << free_pos(tot + 1, j + 1) << "\n";
				//cout << "add2 " << i+1 << " " << j+1 << " " << dp[i][j] * c(free_pos(tot + 1, j + 1), a[i+1] - 1) << "\n";
				add(dp[i+1][j+1], dp[i][j] * c(free_pos(tot, j), a[i+1] - 1));
			
			}
		}
		cout << dp[n][cp_n / 2] << "\n";
		//return 0;
	}
}