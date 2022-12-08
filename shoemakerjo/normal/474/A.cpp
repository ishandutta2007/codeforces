#include <iostream>
#include <string>
using namespace std;

int main() {

	char type;
	cin >> type;
	string mes;
	cin >> mes;
	string k1 = "qwertyuiop";
	string k2 = "asdfghjkl;";
	string k3 = "zxcvbnm,./";
	char cur;
	for (int i = 0; i < mes.length(); ++i) {
		//cout << "bad" << endl;
		cur = mes[i];
		for (int i = 0; i < k1.length(); ++i) {
			if (k1[i] == cur) {
				if (type=='R') {
					cout << k1[i-1];
				}
				else cout << k1[i+1];
			}
		}

		for (int i = 0; i < k2.length(); ++i) {
			if (k2[i] == cur) {
				if (type=='R') {
					cout << k2[i-1];
				}
				else cout << k2[i+1];
			}
		}
		for (int i = 0; i < k3.length(); ++i) {
			if (k3[i] == cur) {
				if (type=='R') {
					cout << k3[i-1];
				}
				else cout << k3[i+1];
			}
		}
	}
	cout << endl;
}