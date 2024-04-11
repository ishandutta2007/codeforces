#include <cstdio>
#include <iostream>

using namespace std;

int n;
string s;

inline void Reverse(int l, int r) {
	int mid = l + r >> 1;
	for (int i = l; i <= mid; i++) {
		char c = s[i];
		s[i] = s[r - i + l];
		s[r - i + l] = c;
	}
}

int main() {
	cin >> n >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			Reverse(1, i);
		}
	}
	for (int i = 1; i < s.size(); i++) {
		putchar(s[i]);
	}
	return 0;
}

// By Sooke.
// CF999B Reversing Encryption.