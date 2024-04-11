#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	int sum = 0;
	for(int i = 1; ; i++) {
		sum += i;
		if(sum > n) {
			cout << i - 1 << endl;
			sum -= i;
			for(int j = 1; j < i - 1; j++) cout << j << ' ';
			cout << n - (sum - i + 1) << endl;
			break;
		}
	}
	return 0;
}