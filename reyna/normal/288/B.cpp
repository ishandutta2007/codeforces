//In the name of God
#include <iostream>
using namespace std;
const int Mod = 1e9 + 7;
long long pw(long long a,long long b){
	if(!b)
		return 1;
	return (pw((a * a)%Mod,b/2) * ((b % 2)?a:1))%Mod;
}
int main(){
	long long n,k;
	cin >> n >> k;
	cout << (((k * pw(k,k-2))% Mod) * (pw(n-k,n-k))%Mod) % Mod << endl;
	return 0;
}