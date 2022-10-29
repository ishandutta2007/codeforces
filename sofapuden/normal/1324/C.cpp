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

		string tmp;
		cin >> tmp;
		int maxsize = 0;
		int currsize = 1;

		rep(i, 0, tmp.size()) {
			if (tmp[i] == 'L') {
				currsize += 1;
			}
			else {
				if (maxsize < currsize) {
					maxsize = currsize;
				}
				currsize = 1;
			}
		}
		if (maxsize < currsize) {
			maxsize = currsize;
		}
		cout << maxsize << "\n";


	}

	return 0;
}