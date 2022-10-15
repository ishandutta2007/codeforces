#include <iostream>
#include <cstdio>

using namespace std;

string s[4];

bool check() {
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (s[i][j] != s[4 - i][4 - j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	for (int i = 1; i <= 3; i++) {
		cin >> s[i];
		s[i] = " " + s[i];
	}
	if (check()) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}

// By Sooke.
// CF12A Super Agent.