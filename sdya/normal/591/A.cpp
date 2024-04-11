#include <iostream>
#include <set>
using namespace std;

int main() {
	// your code goes here
	double l, p, q;
	cin >> l >> p >> q;
	
	double t = l / (p + q);
	cout << t * p << endl;
	return 0;
}