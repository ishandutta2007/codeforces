#include<bits/stdc++.h>
using namespace std;

#define N 100010

int a[N], b[N], c[N], p, mod, n, m, gas[N];

vector <int> dp;

int powmod(int x, int k){
	int ret = 1;
	while( k ){
		if(k & 1) ret = (1ll * ret * x) % p;
		x = 1ll * x * x % p;
		k >>= 1;
	} return ret;
}

int main(){
	scanf("%d %d %d", &n, &m, &p);
	mod = p - 1;
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);

	int btot = mod;
	for(int j = 1; j <= m; j ++) {
		scanf("%d", b + j);
		btot = __gcd( b[j], btot);
	}

	dp.push_back(1);
	int x = mod;
	for(int i = 2; i <= sqrt(mod); i ++){
		if(x % i == 0){
			int cnt = 0;
			while(x % i == 0){
				cnt ++;
				x /= i;
			}
			int tmp = 1;
			int sz = dp.size();
			for(int j = 1; j <= cnt; j ++){
				tmp = tmp * i;
				for(int t = 0; t < sz; t ++) dp.push_back(dp[t] * tmp);
			}
		}
	}
	if(x > 1){
		int sz = dp.size();
		for(int t = 0; t < sz; t ++) dp.push_back(dp[t] * x);
	}
//	cout << btot << endl;
	//cout << dp.size() << endl;
	for(int i = 1; i <= n; i ++){
		for(auto y : dp){
			if(powmod(a[i], y) == 1){ c[i] = mod / y; break; }
		}
		c[i] = __gcd( 1ll * mod, 1ll * c[i] * btot);
		//cout << c[i] << endl;
	}

	for(int i = 0; i < dp.size(); i ++){ int y = dp[i];
		assert(y);
		for(int j = 1; j <= n; j ++){
			//assert(c[i]);
			if(y % c[j] == 0){ gas[i] = mod / y; break; }
		} //cout <<"AA" << y << " " << gas[i] << endl;
	}
	//return 0;

	int sum = 0;
	for(int i = dp.size(); i --; ){
		int z = dp[i];
		sum += gas[i];
		for(int j = dp.size(); j --; ){ int y = dp[j];
			if(y < z && z % y == 0 && gas[j]) gas[j] -= gas[i];
		}
	}
	cout << sum << endl;
}