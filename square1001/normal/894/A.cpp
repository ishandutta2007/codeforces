#include <string>
#include <iostream>
using namespace std;
string s;
int main() {
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); ++i) {
		for(int j = i + 1; j < s.size(); ++j) {
			for(int k = j + 1; k < s.size(); ++k) {
				if(s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') {
					++cnt;
				}
			}
		}
	}
	cout << cnt << endl;
}