#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


const int ma = 5;
const int mb = 20;
string s;
int n;
int a, b;


int main() {
	cin >> s;
	n = s.size();
	a = 1;
	for (; a <= ma; ++a) {
		if (mb * a >= n) {
			break;
		}
	}
	b = ceil((double)(n) / a);
	int k = n % a;
	int i = 0;
	cout << a << " " << b << "\n";
	for (int j = 0; j < a; ++j) {
		if (j < k || k == 0) {
			for (int x = 0; x < b; ++x) {
				cout << s[i];
				++i;
			}
		}
		else {
			for (int x = 0; x < b - 1; ++x) {
				cout << s[i];
				++i;
			}
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}