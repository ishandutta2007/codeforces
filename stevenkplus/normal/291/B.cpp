#include <cstdio>
#include <iostream>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

string s;
int main() {
	getline(cin, s);

	string tmp;
	bool inqt = false;

	repi(i, s) {
		if (*i == '"') {
			if (inqt) {
				cout << "<" << tmp << ">" << "\n";
				inqt = false;
				tmp = "";
			} else {
				inqt = true;
			}
		} else if (inqt || *i != ' ') {
			tmp += *i;
		} else {
			if (!tmp.empty()) {
				cout << "<" << tmp << ">" << "\n";
				tmp = "";
			}
		}
	}

	if (!tmp.empty()) {
		cout << "<" << tmp << ">" << "\n";
	}

	return 0;
}