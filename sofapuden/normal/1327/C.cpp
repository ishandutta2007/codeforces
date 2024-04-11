#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

int main() {

	int x, y;
	cin >> x >> y;

	cout << x + y*2 - 3 + (x - 1) * y << "\n";
	rep(i, 0, x-1) {
		cout << 'D';
	}
	rep(i, 0, y - 1) {
		cout << 'R';
	}
	rep(i, 0, y-1) {
		cout << 'L';
	}
	rep(i, 0, x-1) {
		cout << 'U';
		rep(j, 0, y-1) {

			if (i % 2 == 0) {
				cout << 'R';
			}
			else {
				cout << 'L';
			}
		}

	}
	cout << "\n";
	return 0;
}