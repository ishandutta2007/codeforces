#include<bits/stdc++.h>

using namespace std;
int main() {

	char s[11];
	string rlt = "", cur;

	cin >> s;
	
	int l = strlen(s);
	rlt = "a";

	for (int i = 1; i < (1 << l); i ++) {
		cur = "";
		for (int j = 0; j < l; j ++) if (i & (1 << j)) {
			cur += s[j];
		}
		int ll = cur.length(), ok = 0;
		for (int j = 0; j < ll; j ++) {
			if (cur[j] != cur[ll - j - 1]) {
				ok = 1;
				break;
			}
		}
		if (ok) continue;
		if (cur > rlt) rlt = cur;
	}
	cout << rlt << endl;
	return 0;
}