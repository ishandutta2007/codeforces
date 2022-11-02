#include <bits/stdc++.h>
using namespace std;
string s1, s2, t;
int main() {
	cin >> s1 >> s2 >> t;
	for(char c : t) putchar(c < 58 ? c : s2[s1.find(c < 91 ? c + 32 : c)] - (c < 91 ? 32 : 0));
	return 0;
}