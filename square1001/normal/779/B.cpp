#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string s; int x;
int main() {
	cin >> s >> x;
	int mul = 1;
	for (int i = 0; i < x; i++) mul *= 10;
	int ret = 999999999;
	for (int i = 0; i < 1 << s.size(); i++) {
		string t; int c = s.size();
		for (int j = 0; j < s.size(); j++) {
			if (i & (1 << j)) t += s[j], c--;
		}
		if (t.size() && (t.size() == 1 || t[0] != '0') && stoi(t) % mul == 0) {
			ret = min(ret, c);
		}
	}
	cout << ret << endl;
	return 0;
}