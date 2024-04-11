#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int fac[1000050];
int inv[1000050];

ll fp(ll base, ll exp){
	ll t;
	if(exp == 0) return 1;
	return (exp%2==1?(base*fp(base,exp-1))%mod:(t*(t=fp(base,exp/2)))%mod);
}

int cnt[130];

ll get_fac(int n){
	if(n < 1000050 && fac[n] != -1) return fac[n];
	ll res = 1;
	for(int i = 2; i <= n; i++){
		res = (res * i) % mod;
	}
	if(n < 1000050) fac[n] = res;
	return res;
}

ll get_inv(int n){
	if(n < 1000050 && inv[n] != -1) return inv[n];
	ll res = fp(n, mod-2);
	if(n < 1000050) inv[n] = res;
	return res;
}

ll getres(string a, string k){
	ll res = 0;
	
	fill(cnt, cnt+130, 0);
	for(int i = 0; i < a.length(); i++) cnt[a[i]]++;
	ll mtplr = 1;
	mtplr *= get_fac(a.length());
	for(int i = 'a'; i <= 'z'; i++){
		if(cnt[i] == 0) continue;
		ll dvdnd = get_fac(cnt[i]);
		mtplr = (mtplr * get_inv(dvdnd)) % mod;
	}
	for(int i = 0; i < a.length(); i++){
		ll sum = 0, j = 'a';
		while(j <= 'z'&& j < k[i]){sum += cnt[j]; j++;}
		ll addid = (mtplr * sum) % mod;
		addid = (addid * get_inv(a.length()-i)) % mod;
		res = (res + addid) % mod;
		
		if(cnt[k[i]] <= 0) break;
		
		cnt[k[i]] --;
		mtplr = (mtplr * (cnt[k[i]]+1)) % mod;
		mtplr = (mtplr * get_inv(a.length()-i)) % mod;
	}
	return res;
}


int main(){
	
	string a, b;
	getline(cin, a);
	getline(cin, b);
	fill(inv, inv + 1000050, -1);
	fill(fac, fac + 1000050, -1);
	ll res = getres(a, b) - getres(a, a) -1;
	cout << (res + mod) % mod;
}