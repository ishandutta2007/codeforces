#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll t; cin >> t;
	while(t--){
		ll n, m, x; cin >> n >> m >> x;
		x--;
		ll a = x/n;
		ll b = x%n;
		cout << m*b+a+1 << "\n";
	}
}