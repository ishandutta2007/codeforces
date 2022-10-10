#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	if(a == b)
		cout << 2*c + a + b;
	else
		cout << 2*c + 2*min(a, b) + 1;
}