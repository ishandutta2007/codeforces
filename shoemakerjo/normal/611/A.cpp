#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int num;
	string of;
	string type;
	cin >> num >> of >> type;
	map<int, int> t1;
	t1[1] = 52;
	t1[2] = 52;
	t1[3] = 52;
	t1[4] = 52;
	t1[5] = 53;
	t1[6] = 53;
	t1[7] = 52;


	if (type == "week") {
		cout << t1[num];
	}
	else {
		if (num == 31) cout << 7;
		else if (num == 30) cout << 11;
		else cout << 12;
	}
	cout << endl;
	// cin >> num;

}