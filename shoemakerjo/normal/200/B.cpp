#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin >> n;
	double avg = 0;
	double cur = 0;
	for (int i = 0; i < n; ++i) {
		cin >> cur;
		avg+=cur;
	}
	avg = avg/n;
	cout << fixed << setprecision(5) << avg << endl;

}