#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <char, char> cc;

set <cc> S;
string s;

int main() {
	S.insert(cc('A', 'A'));
	S.insert(cc('b', 'd'));
	S.insert(cc('d', 'b'));
	S.insert(cc('H', 'H'));
	S.insert(cc('I', 'I'));
	S.insert(cc('M', 'M'));
	S.insert(cc('O', 'O'));
	S.insert(cc('o', 'o'));
	S.insert(cc('p', 'q'));
	S.insert(cc('q', 'p'));
	S.insert(cc('T', 'T'));
	S.insert(cc('U', 'U'));
	S.insert(cc('V', 'V'));
	S.insert(cc('v', 'v'));
	S.insert(cc('W', 'W'));
	S.insert(cc('w', 'w'));
	S.insert(cc('X', 'X'));
	S.insert(cc('x', 'x'));
	S.insert(cc('Y', 'Y'));
	cin >> s;
	int l = 0, r = s.length() - 1;
	while (l <= r) {
		if (S.find(cc(s[l], s[r])) == S.end()) break;
		l++; r--;
	}
	printf("%s\n", l <= r? "NIE": "TAK");
}