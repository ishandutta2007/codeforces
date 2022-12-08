#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "I ";
		if (i %2==1) {
			cout << "hate ";
		}
		else {
			cout << "love ";
		}
		if (i == n) {
			cout << "it" << endl;
		}
		else cout <<"that ";
	}
}