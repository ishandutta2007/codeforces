#include <bits/stdc++.h>

using namespace std;

int main() {
	int _;
	cin >> _;
	while (_ --) {
		int n;
		string str;
		cin >> n;
		cin >> str;
		int c = 0, r = n;
		for (int i = 0; i < n; i ++) {
			if (str[i] == '(' && r > 1) c ++, r -= 2, i ++;
			else {
				int j = i + 1;
				while (j < n && str[j] == '(') j ++;
				if (j < n) c ++, r -= (j - i + 1);
				i = j;
			}
		}
		cout << c << " " << r << "\n";
	}
	return 0;
}