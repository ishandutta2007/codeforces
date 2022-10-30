#include <string>
#include <iostream>
using namespace std;
int n, x; string s;
int main() {
	cin >> n;
	int t = 0; bool flag = true;
	for (int i = 0; i < n; i++) {
		cin >> x >> s;
		if (t == 0 && s != "South") flag = false;
		if (t == 20000 && s != "North") flag = false;
		if (s == "South") t += x;
		if (s == "North") t -= x;
		if (t < 0 || t > 20000) flag = false;
	}
	if (t != 0) flag = false;
	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}