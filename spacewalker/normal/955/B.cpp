#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s; cin >> s;
	map<char, int> occt;
	for (char c : s) {
		++occt[c];
	}
	if (occt.size() == 1 || occt.size() > 4) {
		cout << "nO" << endl;
	} else if (occt.size() == 4) {
		cout << "YES" << endl;
	} else {
		vector<int> ocnm;
		for (auto kvp : occt) {
			ocnm.push_back(kvp.second);
		}
		int onect = count_if(ocnm.begin(), ocnm.end(), [] (int x) {return (x > 1);});
		if (occt.size() == 3) {
			cout << (onect >= 1 ? "yes" : "no") << endl;
		} else {
			cout << (onect == 2 ? "yEs" : "No") << endl;
		}
	}
	return 0;
}