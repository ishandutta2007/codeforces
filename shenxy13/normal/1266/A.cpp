#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		bool zer = false, eve = false;
		int sum = 0;
		for (char c: s) {
			if (c == '0') {
				if (!zer) zer = true;
				else eve = true;
			} else if ((c - '0') % 2 == 0) eve = true;
			sum += c - '0';
		}
		if ((zer && eve && sum % 3 == 0) || s == "0") printf("red\n");
		else printf("cyan\n");
	}
	return 0;
}