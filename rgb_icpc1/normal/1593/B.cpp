#include <bits/stdc++.h>

using namespace std;

string s;
int rlt;

int main () {
	int t;
	cin >> t;
	while (t--) {
		rlt = 30;
		cin >> s;
		int sz = s.size(), flg = 0, num;
		for (int i = sz - 1; i >= 0; i--) for (int j = i - 1; j >= 0; j --) {
			num = s[j] - '0';
			num = num * 10 + s[i] -'0';
			if (num % 25 == 0) {
				rlt = min (rlt, sz - j - 2);
			}
		}
		cout << rlt << endl;
		
	}
	
}