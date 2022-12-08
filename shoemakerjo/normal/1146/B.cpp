#include <bits/stdc++.h>

using namespace std;

string t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	bool ok = true;

	vector<char> vc;
	for (int i = 0; i < t.length(); i++) {
		if (t[i] != 'a') vc.push_back(t[i]);
	}
	if (vc.size() % 2 == 1) {
		cout << ":(" << endl;
		return 0;
	}
	string fi = "";
	string se = "";
	for (int i = 0; i < vc.size()/2; i++) {
		fi += vc[i];
	}
	for (int i = vc.size()/2; i < vc.size(); i++) {
		se += vc[i];
	}
	if (fi != se) {
		cout << ":(" << endl;
		return 0;
	}

	//end must match it
	int nchar = t.length();
	nchar -= fi.length();

	if (t.substr(nchar) == se) {
		cout << t.substr(0, nchar) << endl;
	}
	else {
		cout << ":(" << endl;
	}

}