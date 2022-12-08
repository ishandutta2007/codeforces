#include <iostream>

using namespace std;

int main() {
	int n;
	long long x;
	cin >> n >> x;
	char type;
	long long num;
	int distressed = 0;
	for (int i = 0; i < n; i++) {
		cin >> type >> num;
		if (type == '+') x+=num;
		else {
			if (x >= num) {
				x-=num;
			}
			else distressed++;
		}
	}
	cout << x << " " << distressed << endl;
	// cin >> n;
}