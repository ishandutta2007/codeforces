#include <iostream>
#include <string>
using namespace std;

int main() {
	int a1, a2, a3, a4;
	cin >> a1 >> a2 >> a3 >> a4;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		int temp = s[i]-'0';
		if (temp == 1) ans+=a1;
		if (temp == 2) ans+=a2;
		if (temp == 3) ans+=a3;
		if (temp == 4) ans+=a4;
	}
	cout << ans << endl;
}