#include<bits/stdc++.h>
using namespace std;

long long a, b;

int main(){
	cin >> a >> b;
	long long d = __gcd(a, b);
	a /= d;
	b /= d;
	long long ans = 0;
	while(a){
		ans += a / b;
		a %= b;
		if(a == 0) break;
		swap(b, a);
	}
	cout << ans << endl;
}