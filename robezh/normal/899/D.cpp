#include<cstdio>
#include<iostream>
using namespace std;

typedef long long ll;
int n9 = 0;
int mod = 1;

int main(){
	ll n;
	cin >> n;
	if(n < 5){
		if(n == 2) return !printf("1\n");
		if(n == 3) return !printf("3\n");
		if(n == 4) return !printf("6\n");
	}
	ll k = 5;
	while(n >= k){
		n9++; k*=10;
	}
	//cout << n9;
	for(int i = 0; i < n9; i++) mod *= 10;
	
	
	//printf("mod = %d\n", mod);
	int res;
	int base = n/mod;
	if(n % mod == 0){
		res = base * base * (mod / 2);
	}
	else if(n % mod == mod - 1){
		res = base * (base+1) + (mod/2 - 1) * (base+1) * (base +1);
	}
	else if(n % mod <= (mod/2 -1)){
		int k = n % mod;
		res = (k) * (base + 1) * base + (mod/2 - k) * base * base;
	}
	else if(n % mod >= mod/2){
		int k = n % mod - mod/2 + 1;
		//cout << "k = " << k << endl;
		res = k * (base + 1) * (base + 1) + (mod/2 - k - 1) * (base + 1) * base + base * base; 
	}
	
	cout << res;
	
}