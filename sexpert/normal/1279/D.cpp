#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MAXN = 1e6 + 10;
ll prob[MAXN], cnt[MAXN], inv[MAXN];

ll mpow(ll b, ll e) {
	ll res = 1;
	for(ll k = 1; k <= e; k*=2) {
        //cout << b << " " << k << " " << e << endl;
		if(k & e) res = (res * b) % MOD;
		b = (b * b) % MOD;
	}
	return res;
}

ll _inv(ll b) {
	return mpow(b, MOD - 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    //cout << "inv start" << endl;
	for(int i = 1; i < MAXN; i++)
	    inv[i] = _inv(i);
	
    //cout << "inv done" << endl;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int k;
		cin >> k;
	    for(int j = 0; j < k; j++) {
	    	int p;
	    	cin >> p;
	    	cnt[p]++;
	    	prob[p] += inv[k];
	    	if(prob[p] >= MOD)
	    		prob[p] -= MOD;
	    }
	}
	ll isq = (inv[n] * inv[n]) % MOD;
	ll ans = 0;
	for(int i = 0; i < MAXN; i++) {
		ans = (ans + prob[i] * cnt[i]) % MOD;
	}
	ans = (ans * isq) % MOD;
	cout << ans << '\n';
}