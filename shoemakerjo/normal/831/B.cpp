#include <iostream>
#include <string>
using namespace std;

int main() {
	string first, second;
	cin >> first >> second;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		bool found = false;
		for (int j = 0; j < 26; j++) {
			if (first[j]== s[i]) {
				cout << second[j];
				found = true;
				break;
			}
			else {
				char c = tolower(s[i]);
				if (first[j] == c) {
					cout << (char) toupper(second[j]) ;
					found = true;
					break;
				}
			}
		
		}
		if (!found) cout << s[i];
	}
	cout << endl;
	cin >> s;
}