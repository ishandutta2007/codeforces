#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)

using namespace std;

int main() {
	
	int N, hard;
	cin >> N;
	hard = 0;
	rep(i, 0, N) {
		int tmp;
		cin >> tmp;
		if (tmp == 1) {
			hard = 1;
		}

	}
	if (hard == 1) {
		cout << "HARD\n";
	}
	else {
		cout << "EASY\n";
	}

	return 0;
}