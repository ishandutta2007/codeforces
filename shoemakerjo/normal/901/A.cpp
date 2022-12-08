#include <bits/stdc++.h>

using namespace std;

int main() {
	int h;
	cin >> h;
	int vals[h+2];
	for (int i = 0; i <= h; i++) {
		cin >> vals[i+1];
	}
	int nh[h+2];
	int sec[h+2];
	nh[0] = 0;
	sec[0] = -1;
	for (int i = 1; i <= h+1; i++) {
		nh[i] = -1;
		sec[i] = -1;
	}
	bool change = false;
	vector<int> o1;
	vector<int> o2;
	int ct = 0;
	for (int i = 1; i <= h+1; i++) {
		if (!change && sec[i-1] != -1 && vals[i] > 1) {
			o1.push_back(nh[i-1]);
			o2.push_back(sec[i-1]);
			change = true;
		}
		else {///
			o1.push_back(nh[i-1]);
			o2.push_back(nh[i-1]);	
		}
		nh[i] = ++ct;
		for (int j = 2; j <= vals[i]; j++) {
			ct++;
			o1.push_back(nh[i-1]);
			o2.push_back(nh[i-1]);
			sec[i] = ct;
		}
		// cout << "i " << nh[i] << endl;
	}
	if (!change) {
		cout << "perfect" << endl;
	}
	else {
		cout << "ambiguous" << endl;
		for (int i = 0; i < o1.size(); i++) {
			cout << o1[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < o2.size(); i++) {
			cout << o2[i] << " ";
		}
		cout << endl;
	}
	cin >> h;
}