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

map <ll, bool> m;

bool calc(ll n){
	if(m.find(n) != m.end()){
		return m[n];
	}
	bool fl = true;
	for(ll i = 2; i * i <= n; i++){
		if(n % i == 0){
			fl = false;
			break;
		}
	}
	if(fl){
		return m[n] = true;
	}
	bool can = false;
	for(ll i = 2; i * i <= n; i++){
		if(n % i == 0){
			fl = true;
			if(!calc(i)){
				can = true;
				break;
			}
			if(!calc(n / i)){
				can = true;
				break;
			}
		}
	}
	return m[n] = can;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n;
	scanf("%I64d", &n);
	if(calc(n)){
		printf("1\n");
		bool fl = true;
		for(ll i = 2; i * i <= n; i++){
			if(n % i == 0){
				fl = false;
				break;
			}
		}
		if(fl){
			printf("0\n");
			return 0;
		}
		for(ll i = 2; i * i <= n; i++){
			if(n % i == 0){
				if(!calc(i)){
					printf("%I64d\n", i);
					return 0;
				}
				if(!calc(n / i)){
					printf("%I64d\n", n / i);
					return 0;
				}
			}
		}
		return 0;
	}
	printf("2\n");
	return 0;
}