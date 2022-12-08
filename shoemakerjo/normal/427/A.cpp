#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int crimes = 0;
	int manpower = 0;
	int cur;
	for (int i = 0; i < n; ++i) {
		cin >> cur;
		if (cur == -1) {
			if (manpower == 0) crimes++;
			else manpower--;
		}
		else manpower+=cur;
	}
	cout << crimes << endl;
}