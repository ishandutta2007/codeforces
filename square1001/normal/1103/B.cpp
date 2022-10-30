#include <string>
#include <iostream>
using namespace std;
string ask(int x, int y) {
	cout << "? " << x << ' ' << y << endl;
	string res;
	cin >> res;
	return res;
}
int main() {
	while (true) {
		string tp;
		cin >> tp;
		if (tp != "start") break;
		int val = 1;
		while (true) {
			string res = ask(val, val * 2);
			if (res == "x") break;
			val *= 2;
		}
		if (val == 1) {
			string res = ask(2, 3);
			if (res == "x") --val;
		}
		else {
			int st = val;
			for (int i = val / 2; i >= 1; i /= 2) {
				string res = ask(st, val + i);
				if (res == "y") val += i;
			}
		}
		cout << "! " << val + 1 << endl;
	}
	return 0;
}