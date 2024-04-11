#include <iostream>
#define ll long long
using namespace std;

int main() {
	int t;
	cin >> t;
	ll n, pow, sum;
	for (int i = 0; i < t; i++) {
		cin >> n;
		pow = 1;
		sum = n*(n+1)/2;
		while (pow <= n) {
			// cout << n << "   -   " << pow << endl;
			pow*=2;
			sum-=pow;
		}
		cout << sum << endl;
	}
	// cin >> n;
	
}