#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string s, t;
int main() {
	cin >> s >> t;
	if (s != t) cout << max(s.size(), t.size()) << endl;
	else cout << -1 << endl;
	return 0;
}