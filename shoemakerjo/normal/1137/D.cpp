#include <bits/stdc++.h>

using namespace std;

int getgroups() {
	int num;
	cin >> num;
	int garb;
	for (int i = 0; i < num; i++) {
		cin >> garb;
	}
	return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "next 0 1" << endl;
	getgroups();
	cout << "next 1" << endl;

	while (getgroups() != 2) {
		cout << "next 0 1" << endl;
		getgroups();
		cout << "next 1" << endl;
	}

	//now we know there are 2 groups

	do {
		cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
	} while (getgroups() != 1);

	cout << "done" << endl;

}