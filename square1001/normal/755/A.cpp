#include <vector>
#include <iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	if (n <= 2) cout << n + 2 << endl;
	else cout << n - 2 << endl;
	return 0;
}