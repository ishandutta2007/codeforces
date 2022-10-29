#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)

using namespace std;


int main() {

	string luckynumber;
	cin >> luckynumber;
	int t = 0;

	rep(i, 0, luckynumber.size()) {
		if (luckynumber[i] == '4' || luckynumber[i] == '7') {
			t++;
		}
	}

	if (t == 4 || t == 7) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}