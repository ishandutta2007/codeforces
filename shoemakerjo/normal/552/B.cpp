#include <iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long dig = 0;
	long long curpow = 1;
	long long places = 1;
	while (curpow*10 <= n) {
		dig += 9*curpow*places;
		places++;
		curpow*=10;
	}
	dig += places*(n-curpow+1);
	cout << dig << endl;
	// cin >> n;

}