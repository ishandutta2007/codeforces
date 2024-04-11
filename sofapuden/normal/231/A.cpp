#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)

using namespace std;

int main() {
	
	int N, result;
	result = 0;
	
	cin >> N;

	rep(i, 0, N) {
		vector <int> tmpv;
		int u = 0;
		rep(j, 0, 3) {
			int tmpi;
			cin >> tmpi;
			tmpv.push_back(tmpi);
		}
		rep(j, 0, 3) {
			if (tmpv[j] == 1) {
				u += 1;
			}
		}
		if (u > 1) {
			result += 1;
		}
	}

	cout << result << "\n";

	return 0;
}