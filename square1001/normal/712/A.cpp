#include <iostream>
using namespace std;
int n, a[100009];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cout << a[i] + a[i + 1] << ' ';
	cout << endl;
	return 0;
}