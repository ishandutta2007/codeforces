#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
	cin >> t;
	while (t --) {
		string s1, s2;
		cin >> s1 >> s2;
		vector<char> v1(0);
		vector<char> v2(0);
		int x = 0;
		for (int i = 0; s1[i]; i ++) if (s1[i] == 'B') x ^= 1;
		for (int i = 0; s2[i]; i ++) if (s2[i] == 'B') x ^= 1;

		if (x) {
			cout << "NO" << "\n"; continue;
		} 

		for (int i = 0; i < s1.length(); i ++)  {
			if (s1[i] == 'B') continue;
			if (v1.size() == 0) {
				v1.push_back(s1[i]);
			} else {
				//cout << "dog" << "\n";
				if (v1.back() == s1[i]) v1.pop_back(); else v1.push_back(s1[i]);
			}
		}
		//for (auto c: v1) cout << c << "\n";
		for (int i = 0; i < s2.length(); i ++)  {
			if (s2[i] == 'B') continue;
			if (v2.size() == 0) v2.push_back(s2[i]);
			else {
				if (v2.back() == s2[i]) v2.pop_back(); else v2.push_back(s2[i]);
			}
		}
		cout << (v1==v2?"YES":"NO") << "\n";
	}
}

/*
A <-> BAB
B <-> ABA

C <-> BCB
B <-> CBC

ABC -> ABBCB -> ACB -> 

BC -> BBCB -> CB
AB -> AABA -> BA

AC -> 
*/