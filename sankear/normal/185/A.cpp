#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>
 
using namespace std;

typedef long long ll;

const ll MOD = (ll)(1e9 + 7);

inline ll calc(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b % 2 != 0){
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
}

inline ll get(ll l, ll r){
	ll p1 = (calc(2, r + 1) - 1 + MOD) % MOD;
	ll p2 = (calc(2, l) - 1 + MOD) % MOD;
	return (p1 - p2 + MOD) % MOD;
}
 
int main(){
	//freopen("addict.in", "r", stdin);
	//freopen("addict.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n;
	cin >> n;
	if(n == 0){
		cout << 1 << endl;
		return 0;
	}
	ll ans = (calc(4, n) - get(n - 1, 2 * n - 2) + MOD) % MOD;
	cout << ans << endl;
	return 0;
}