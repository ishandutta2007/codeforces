#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int c = 0;
	int bi = 0;
	int ba = 0;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (i%3 == 0) c+=cur;
		else if (i%3==1) bi+=cur;
		else ba+=cur;
	}
	if (c > bi && c > ba) cout << "chest" << endl;
	else if (bi > c && bi > ba) cout << "biceps" << endl;
	else cout << "back" << endl;
	// cin >> n;
}