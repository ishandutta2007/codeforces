#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll a, b; cin >> a >> b;
	if(b == 1)cout << a-1 << '\n';
	else cout << (b-1)*a << '\n';
}