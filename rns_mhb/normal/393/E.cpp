#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define N 50

typedef pair<int, int> pii;

long long n;
int k, C[N][N], pw[N], p1[N], p2[N];

pii fib(long long x) {
	if (!x) return make_pair(1, 1);
	pii ff;
	if (x % 2) {
		ff = fib((x - 1) / 2);
		return make_pair((int)(1LL * ff.first * (2ll * ff.second - ff.first) % mod), (int)(1LL * ff.first * ff.first % mod + 1ll * ff.second * ff.second %mod) % mod);
	}
	else {
		ff = fib((x - 2) / 2);
		return make_pair((int)(1LL * ff.first * ff.first % mod + 1ll * ff.second * ff.second % mod) % mod, (int)(1LL * ff.second * (ff.second + 2ll * ff.first) % mod));
	}
}

int calc(long long n, int k) {
	int ans[N], f2 = fib(n + 2).first, f1 = fib(n + 1).first;

	ans[0] = (f2 - 2) % mod;
	//cout<<p2[i + 1];
	//cout<<ans[0];
	for(int i = 1; i <= k; i ++){
		ans[i] = (pw[i + 1] - (1ll * p2[i] * f2) % mod) % mod;
		for(int j = 1; j <= i; j ++){
			ans[i] += (1ll * C[i][j] * ((1ll * ans[i - j] * (pw[j] + 1)) % mod + (1ll * p1[i - j] * f1) % mod - 1)) % mod;
			ans[i] %= mod;
		}
		ans[i] = (- ans[i]) % mod;
		//cout<<ans[i]<<endl;
	}
	return (ans[k] + mod) % mod;
}

int main() {
	scanf("%I64d %d", &n, &k);
    for (int i = 0; i < N; i ++) C[i][0] = 1, C[i][i] = 1;
    for (int i = 1; i < N; i ++) {
		for (int j = 1; j < i; j ++) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			C[i][j] %= mod;
		}
    }
    for(int i = 0; i < N; i ++){
		if(i == 0)	pw[0] = 1, p1[0] = 1, p2[0] = 1;
		else pw[i] = (2ll * pw[i - 1]) % mod, p1[i] = (1ll * p1[i - 1] * (n % mod + 1)) % mod, p2[i] = (1ll * p2[i - 1] * (n % mod + 2)) % mod;
	}
    printf("%d\n", calc(n, k));
    //cout<<C[10][3];
	//for(int i = 0; i < 10; i ++)	cout<<p[i]<<endl;
}