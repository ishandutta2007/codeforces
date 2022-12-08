#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {

	map<string, int> m;
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (m.count(s) > 0) {
			cout << s << m[s] << '\n';
			m[s] = m[s]+1;
		}
		else {
			cout << "OK" << '\n';
			m[s] = 1;
		}
	}
}