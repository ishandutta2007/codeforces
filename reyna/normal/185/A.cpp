//In the name of God
#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;
long long pw(long long a,long long b){
	return b?(pw((a * a) % Mod,b >> 1) * (b & 1?a:1)) % Mod:1;
}
int main(){
	long long x;
	cin >> x;
	x = pw(2,x);
	x = (x * (x + 1)) / 2;
	x %= Mod;
	cout << x << endl;
	return 0;
}