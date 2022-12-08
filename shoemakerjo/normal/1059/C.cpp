#include <bits/stdc++.h>

using namespace std;

int n;

int mult;

void go (int val) {
	if (val == 1) {
		cout << 1*mult << " ";
		return;
	}
	if (val == 2) {
		cout << 1*mult << " " << 2*mult << " ";
		return;
	}
	if (val == 3) {
		cout << 1*mult << " " << 1*mult << " " << 3*mult;
		return;
	}
	int numrem = (val+1)/2;
	for (int i = 0; i < numrem; i++) {
		cout << mult << " ";
	}
	mult*=2;
	go(val/2);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	mult = 1;
	go(n);
	cout << endl;
}