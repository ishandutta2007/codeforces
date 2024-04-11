#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)

using namespace std;

int main() {

	int t;
	cin >> t;

	rep(i, 0, t) {

		int n;
		cin >> n;
		int u = 0;

		vector <int> setup;

		int maxnumber = 0;
		rep(j, 0, n) {
			int tmp;
			cin >> tmp;
			if (tmp > maxnumber) {
				maxnumber = tmp;
			}
			setup.push_back(tmp);
		}


		rep(j, 0, n) {
			if ((maxnumber - setup[j]) % 2 == 0) {

			}
			else {
				u = 1;
			}
		}

		if (u == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}

	return 0;
}