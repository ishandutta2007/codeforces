#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
const int maxN = 1100;
int a[maxN];

int main() {
	// your code goes here
	cin >> n;
	int s = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++a[x];
		s = (s + x) % 3;
	}
	if (a[0] == 0) {
		cout << -1 << endl;
		return 0;
	}
	if (s % 3 == 0) {
		int total = 0;
		for (int j = 9; j >= 0; --j) {
			if (j == 0 && total == 0) {
				a[j] = 1;
			}
			for (int k = 0; k < a[j]; ++k) {
				cout << j;
				++total;
			}
		}
		
		return 0;
	}
	for (int i = 1; i < 10; ++i) {
		if ((s - i) % 3 == 0 && a[i] > 0) {
			--a[i];
			
			int total = 0;
		for (int j = 9; j >= 0; --j) {
			if (j == 0 && total == 0) {
				a[j] = 1;
			}
			for (int k = 0; k < a[j]; ++k) {
				cout << j;
				++total;
			}
		}
			
			return 0;
		}
	}
	for (int i = 1; i < 10; ++i) {
		for (int j = 1; j <= i; ++j) {
			if ((s - i - j) % 3 == 0) {
				--a[i];
				--a[j];
				if (a[i] >= 0 && a[j] >= 0) {
					int total = 0;
		for (int j = 9; j >= 0; --j) {
			if (j == 0 && total == 0) {
				a[j] = 1;
			}
			for (int k = 0; k < a[j]; ++k) {
				cout << j;
				++total;
			}
		}
					return 0;
				} else {
					++a[i];
					++a[j];
				}
			}
		}
	}
	return 0;
}