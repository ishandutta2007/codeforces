#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const string model = "Yes";

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	int _;
	cin >> _;
	while (_ --) {
		string str;
		cin >> str;
		int j;
		if (str[0] == 'Y') j = 1;
		else if (str[0] == 'e') j = 2;
		else if (str[0] == 's') j = 0;
		else {
			cout << "NO\n";
			continue;
		}
		bool flag = true;
		for (int i = 1; i < str.size(); i++, j++, j %= 3) {
			if (str[i] != model[j]) {
				flag = false;
				break;
			}
		}
		cout << (flag ? "YES\n" : "NO\n");
	}
	return 0;	
}