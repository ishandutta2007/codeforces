#include <bits/stdc++.h>
using namespace std;
int z, t;
int main() {
	string ret;
	for(int i = 0; i < 4; i++) {
		int ptr = -1, res = -1;
		for(int j = 0; j < 10; j++) {
			for(int k = 0; k < 4; k++) cout << (i == k ? j : 0); cout << endl;
			cin >> z >> t;
			if(z == 4 && t == 0) return 0;
			if(z > res) res = z, ptr = j;
		}
		ret += ptr + 48;
	}
	cout << ret << endl;
	cin >> z >> t;
	return 0;
}