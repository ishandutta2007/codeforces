#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, int> mymap;
vector<string> v;

void put(string &s) {
	int &r = mymap[s];
	if (!r) v.push_back(s);
	r++;
}

int gi(string &s, int a, int b) {
	int k = 0;
	for(int i = a; i < a + b; ++i) {
		char c = s[i];
		if (c >= '0' && c <= '9') {
			k *= 10;
			k += c - '0';
		}
		 else return -1;
	}
	return k;
}


bool valid(int day, int mo) {
	if (day > 30) return mo == 1 || mo == 3 || mo == 5 || mo == 7 || mo == 8 || mo == 10 || mo == 12;
	if (day > 28) return mo != 2;
	return true;
}

bool isdate(string s) {
	int a = gi(s, 0, 2), b = gi(s, 3, 2), c = gi(s, 6, 4);
	if (a == -1 || b == -1 || c == -1) return false;
	if (!(s[2] == s[5] && s[5] == '-')) return false;
	if (c >= 2013 && c <= 2015) {
		if (b >= 1 && b <= 12 && a >= 1 && a <= 31) {
			if (valid(a, b)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	string s;
	cin >> s;
	int len = 10;
	for(int i = 0; i + len <= int(s.size()); ++i) {
		string sub = s.substr(i, len);
		if (isdate(sub)) {
			put(sub);
		}
	}
	int m = 0;
	string ans;
	for(int i = 0; i < int(v.size()); ++i) {
		string &s = v[i];
		int k = mymap[s];
		if (k > m) {
			m = k;
			ans = s;
		}
	}
	cout << ans << endl;
}