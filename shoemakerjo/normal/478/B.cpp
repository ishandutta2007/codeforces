#include <iostream>

#define ll long long

using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;

	ll base = n/m;

	ll more = n-base*m;
	ll same = (n-more*(base+1))/base;

	ll kmi = 0;
	kmi += same*(base*(base-1)/2);
	kmi += more*((base+1)*(base)/2);
	ll kma = (n-m+1)*(n-m)/2;
	cout << kmi << " " << kma << endl;
	// cin >> n;
}