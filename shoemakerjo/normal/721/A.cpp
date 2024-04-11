#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool in = false;
	int length = 0;
	vector<int> ls;
	for (int i = 0; i < n; i++) {
		if (s[i]=='B') {
			if (!in) {
				length = 0;
				in = true;
			}
			length++;
		}
		else {
			if (in) {
				ls.push_back(length);
			}
			in = false;
		}
	}
	if (in) ls.push_back(length);

	cout << ls.size() << endl;
	for (int i = 0; i < ls.size(); i++) {
		if (i > 0) cout << " ";
		cout << ls[i];
	}
	cout << endl; 
	// cin >> n;
}