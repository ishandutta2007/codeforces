#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

int main() {
	int n; cin >> n;
	map<string, string> handles; //newName->oldName
	while (n--) {
		string oldName, newName;
		cin >> oldName >> newName;
		if (handles.find(oldName) == handles.end()) {
			handles[newName] = oldName;
		} else {
			string firstName = handles[oldName];
			handles.erase(oldName);
			handles[newName] = firstName;
		}
	}
	cout << handles.size() << endl;
	for (auto namePair : handles) {
		cout << namePair.second << ' ' << namePair.first << endl;
	}
}