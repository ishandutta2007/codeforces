#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int min = n/7;
	min*=2;
	if (n%7 == 6) min++;
	int max = n/7;
	max*=2;
	if (n%7 >= 1) max++;
	if (n%7 >= 2) max++;
	cout << min << " " << max << endl;
	// cin >> n;
}