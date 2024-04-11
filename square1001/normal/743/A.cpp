#include <bits/stdc++.h>
using namespace std;
int n, a, b; string s;
int main() {
	cin >> n >> a >> b >> s; a--, b--;
	if(s[a] == s[b]) cout << 0 << endl;
	else cout << 1 << endl;
	return 0;
}