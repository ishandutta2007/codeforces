#include <set>
#include <string>
#include <iostream>
using namespace std;
string s;
int main() {
	cin >> s;
	int n = s.size(); s += s;
	set<string> x;
	for (int i = 0; i < n; i++) {
		x.insert(s.substr(i, n));
	}
	cout << x.size() << endl;
	return 0;
}