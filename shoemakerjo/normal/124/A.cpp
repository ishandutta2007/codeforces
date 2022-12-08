#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int start = a+1;
	start = max(start, n-b);
	cout << n-start+1 << endl;
	// cin >> n;

}