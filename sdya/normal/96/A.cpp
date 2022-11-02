#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	if (s.find(string(7, '1')) == string::npos && s.find(string(7, '0')) == string::npos) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}
	return 0;
}