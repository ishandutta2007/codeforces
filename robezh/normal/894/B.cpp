#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

typedef long long ll;

int mod = 1000000007;

long long fast_pow(int power){
	if(power == 0) return 1;
	
	if(power % 2 == 0) return ((fast_pow(power / 2) % mod) * (fast_pow(power / 2) % mod)) % mod; 
	return (2 * fast_pow(power - 1)) % mod;
}

int main(){
	ll n,m,k;
	cin >> n >> m >> k;
	if(((n-m) % 2 + 2) % 2 == 1 && k == -1) printf("0");
	else cout << fast_pow((((n - 1) % (mod-1)) * ((m-1) % (mod-1))) % (mod-1));
}