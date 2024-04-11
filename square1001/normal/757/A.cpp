#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int c[133], e[133]; string s, t = "Bulbasaur";
int main() {
	cin >> s;
	for (int i = 0; i < t.size(); i++) e[t[i]]++;
	for (int i = 0; i < s.size(); i++) c[s[i]]++;
	int ret = 999999999;
	for (int i = 0; i < 128; i++) {
		if (e[i] >= 1) ret = min(ret, c[i] / e[i]);
	}
	cout << ret << endl;
	return 0;
}