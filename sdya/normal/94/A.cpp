#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

string s;
map < string, int > M;

int main() {
	cin >> s;
	for (int i = 0; i < 10; ++i) {
		string t;
		cin >> t;
		M[t] = i;
	}
	for (int i = 0; i < s.size(); i += 10) {
		string t = s.substr(i, 10);
		cout << M[t];
	}
	return 0;
}