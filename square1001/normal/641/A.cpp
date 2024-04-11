#include <string>
#include <iostream>
using namespace std;
int n, d[100009]; string s;
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> d[i];
	int pos = 0; bool flag = false;
	for (int i = 0; i < 100000; i++) {
		if (s[pos] == '>') pos += d[pos];
		else pos -= d[pos];
		if(pos < 0 || n <= pos) {
			flag = true;
			break;
		}
	}
	cout << (flag ? "FINITE" : "INFINITE") << endl;
	return 0;
}