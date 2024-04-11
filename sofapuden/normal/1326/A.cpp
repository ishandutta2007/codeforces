#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define ll long long;
using namespace std;


int main() {
	int t;
	cin >> t;

	rep(i, 0, t) {
		int n;
		cin >> n;

		if (n == 1) {
			cout << -1 << "\n";
		}
		else {
			rep(j, 0, n-2) {
				cout << 2;
			}
			if ((n * 2 + 1) % 3 == 0) {
				cout << 3;
			}
			else {
				cout << 2;
			}
			cout << 3 << "\n";

		}
	}
}