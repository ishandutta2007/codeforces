#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	int n; cin >> n; cin.ignore();
	set<string> leaves;
	string leaf;
	while (n--) {
		getline(cin, leaf);
		leaves.insert(leaf);
	}
	cout << leaves.size();
	return 0;
}