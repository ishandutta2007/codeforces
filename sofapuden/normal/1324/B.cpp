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
		vector <int> checkbox(1000000);
		rep(j, 0, n) {
			int tmp;
			cin >> tmp;
			setup.push_back(tmp);
		}
		rep(j, 0, 2) {
			checkbox[setup[j]] += 1;
		}
		rep(j, 2, n) {
			if (checkbox[setup[j]] == 1 && setup[j - 1] != setup[j]) {
				u = 1;
			}
			else if (checkbox[setup[j]] == 2) {
				u = 1;
			}
			else {
				checkbox[setup[j]] += 1;
			}
		}



		if (u == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}

	return 0;
}