#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll x = 810;
	ll a; cin >> a;
	for(int i = 0; i < 17; ++i){
		x*=10;
		x%=a;
	}
	x++;
	x%=a;
	// lef = a-x
	
	cout << a+1-x << ' ' << 1000000000000000000ll+a-x << '\n';

}