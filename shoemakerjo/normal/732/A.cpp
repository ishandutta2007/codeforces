#include <iostream>

using namespace std;

int main() {
	int k, r;
	cin >> k >> r;
	int count = 1;
	int cur = k;
	while ( (cur % 10) != r && (cur % 10) != 0) {
		cur+=k;
		count++;
	}
	cout << count << endl;
}