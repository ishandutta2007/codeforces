#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, X;
	cin >> N >> X;
	int c, sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> c;
		sum += c;
	}
	sum = abs(sum);
	cout << ((sum + X - 1) / X) << endl;
	return 0;
}