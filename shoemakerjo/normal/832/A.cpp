#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	ll take = n-k+1;
	ll div = take/k;
	if (take%k!=0) div++;
	if (div%2==1) cout << "YES" << endl;
	else cout << "NO" << endl;
	cin >> n;
}