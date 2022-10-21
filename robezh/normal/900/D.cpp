#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

map<int, int> M;

ll fp(ll base, ll power){
	if(power == 0) return 1;
	if(power % 2 == 1) return (base * fp(base, power-1)) % mod;
	ll t = fp(base, power/2);
	return (t * t) % mod;
}

ll get_ans(int k){
	if(k == 1) return 1;
	if(M.count(k)) return M[k];
	
	ll ans = fp(2, k-1);
	int up = (int)(sqrt(k));
	for(int i = 2; i <= up; i++){
		if(k % i == 0){
			ans -= get_ans(k/i);
			if(k/i != i) ans -= get_ans(i);
			ans = (ans + 2 * mod) % mod;
		}
	}
	ans -= 1;
	ans = (ans + mod) % mod;
	M[k] = ans;
	return ans;
}

int main(){
	int a, b;
	cin >> a >> b;
	if(b % a != 0) return !printf("0");
	return !printf("%d", get_ans(b/a));
}