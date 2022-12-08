#include <iostream>


using namespace std;

int main() {
	int sticks[6];
	for (int i = 0; i < 6; ++i) {
		cin >> sticks[i];
	}
	bool ok = false;
	int count;
	int leg = 0;
	for (int i = 1; i <= 9; i++) {
		count = 0;
		for (int j = 0; j < 6; j++) {
			if (sticks[j]==i) count++;
		}
		if (count >= 4) {
			ok = true;
			leg = i;
		}
	}
	if (!ok) {
		cout << "Alien" << endl;
	}
	else {
		int o1 = -1;
		int o2 = -1;
		for (int j = 0; j < 6; j++) {
			if (sticks[j]!=leg) {
				if (o1 == -1) o1 = sticks[j];
				else o2 = sticks[j];
			}
		}

		if (o1 == o2) {
			cout << "Elephant" << endl;
		}
		else cout << "Bear" << endl;
	}
	// cin >> sticks[0];
	
}