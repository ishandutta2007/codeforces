#include <cstdio>
#include <iostream>

using namespace std;

#define sz(x) int((x).size())

const string prf1 = "http";
const string pr2 = "ftp";

const string end = "ru";

string process(string s) {
	string ret;
	int start = sz(pr2);
	if (s.substr(0, start) != pr2) {
		start++;
	}
	ret += s.substr(0, start);
	ret += "://";
	int x;
	for (x = start + 1; s.substr(x, 2) != "ru"; ++x);
	ret += s.substr(start, x - start);
	ret += ".ru";
	x += 2;
	if (x != sz(s)) {
		ret += "/";
		ret += s.substr(x);
	}
	return ret;
}

int main() {
	string s;
	cin >> s;
	string ans = process(s);
	cout << ans << endl;
	return 0;
}