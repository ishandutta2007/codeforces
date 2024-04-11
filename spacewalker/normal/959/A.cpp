#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int n; cin >> n;
	cout << (n % 2 == 1 ? "Ehab" : "Mahmoud") << endl;
	return 0;
}