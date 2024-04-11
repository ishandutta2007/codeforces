#include <iostream>
#include <string>
#include <iomanip>

#define max(a, b) (a > b ? a : b)

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	double tmp, prop = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		prop += tmp;
	}
	cout << fixed << setprecision(10) << prop / n << endl;
	return 0;
}