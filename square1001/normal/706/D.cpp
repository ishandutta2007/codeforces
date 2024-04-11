#include <map>
#include <string>
#include <iostream>
using namespace std;
map<int, int> c[32];
int Q, x; string s;
int main() {
	cin >> Q;
	for (int i = 30; i >= 0; i--) c[i][0]++;
	while (Q--) {
		cin >> s >> x;
		if (s == "+") for (int i = 30; i >= 0; i--) c[i][x >> i]++;
		if (s == "-") for (int i = 30; i >= 0; i--) c[i][x >> i]--;
		if (s == "?") {
			int pos = 0;
			for (int i = 30; i >= 0; i--) {
				int r = (x & (1 << i) ? 1 : 0);
				if (c[i][pos * 2 + (r ^ 1)]) pos = pos * 2 + (r ^ 1);
				else pos = pos * 2 + r;
			}
			cout << (pos ^ x) << endl;
		}
	}
	return 0;
}