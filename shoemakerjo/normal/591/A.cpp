#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double l;
	cin >> l;
	double p, q;
	cin >> p >> q;
	cout << fixed;
	cout << setprecision(6);
	cout << p*l/(p+q) << endl;
	// cin >> l;
}