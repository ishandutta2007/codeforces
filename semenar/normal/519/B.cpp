#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#define max(a, b) (a > b ? a : b)

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	long long sum1 = 0, sum2 = 0, sum3 = 0;
	for (int i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		sum1 += tmp;
	}
	for (int i = 1; i < n; i++) {
		long long tmp;
		cin >> tmp;
		sum2 += tmp;
	}
	for (int i = 2; i < n; i++) {
		long long tmp;
		cin >> tmp;
		sum3 += tmp;
	}
	cout << sum1 - sum2 << endl << sum2 - sum3 << endl;
	return 0;
}