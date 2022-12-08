#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int mscore = max(3*a/10, a-a*c/250);
	int vscore = max(3*b/10, b-b*d/250);
	if (mscore > vscore) {
		cout << "Misha" << endl;
	} 
	else if (vscore > mscore) {
		cout << "Vasya" << endl;
	}
	else cout << "Tie" << endl;
	// cin >> a;
}