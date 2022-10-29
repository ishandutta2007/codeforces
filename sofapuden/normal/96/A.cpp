#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)

using namespace std;

int main() {
	
	string player;
	cin >> player;

	int u = 0;
	int t = 0;

	rep(i, 0, player.size()) {
		if (u == 0) {
			if (player[i] == '0') {
				t += 1;
			}
			else {
				u = 1;
				t = 1;
			}
		}
		else {
			if (player[i] == '1') {
				t += 1;
			}
			else {
				u = 0;
				t = 1;
			}
		}
		if (t == 7) {
			cout << "YES\n";
			return 0;
		}

	}
	cout << "NO\n";
	return 0;
}