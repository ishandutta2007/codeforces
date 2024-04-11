#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)

using namespace std;


int main() {
	int n;
	cin >> n;
	int over, under;
	over = 0;
	under = 0;
	rep(i, 0, n) {
		int tmpi;
		cin >> tmpi;

		if (tmpi % 2 == 0) {
			cout << tmpi / 2 << "\n";
		}
		else if (tmpi < 0) {
			if (under == 0) {
				cout << tmpi / 2 - 1 << "\n";
				under = 1;
			}
			else {
				cout << tmpi / 2 << "\n";
				under = 0;
			}

		}
		else {
			if (over == 0) {
				cout << tmpi / 2 + 1 << "\n";
				over = 1;
			}
			else {
				cout << tmpi / 2 << "\n";
				over = 0;
			}
		}
	}
}