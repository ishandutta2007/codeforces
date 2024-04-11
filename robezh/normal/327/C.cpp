#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
string str;
int n, k;
int cons = 0;

int fast_pow(int base, int power){
	
	if(power == 0) return 1;
	//cout << power << endl;
	if(power % 2 == 0){
		ll k = (fast_pow(base, power / 2));
		return (k * k) % mod;
	}
	return ((ll)base * fast_pow(base, power - 1)) % mod;
}

int main(){
	getline(cin, str);
	cin >> k;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '5' || str[i] == '0'){
			cons += fast_pow(2, i);
			cons %= mod;
		}
	}
	int len = str.length();
	int times1 = (fast_pow(fast_pow(2, len), k) - 1 + mod) % mod;
	//cout << "times1 = " << times1 << endl;
	int mod2 = mod -2;
	int times2 = (fast_pow(fast_pow(2, len) - 1, mod-2));
	//cout << "times2 = " << times2 << endl;
	
	int res = ((ll)(((ll)times1 * times2) % mod) * cons) % mod;
	
	cout << res;
	
}