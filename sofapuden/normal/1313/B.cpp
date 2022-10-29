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

	while (t--) {

		int n, x, y;
		cin >> n >> x >> y;
		cout << min(n, max(1, x + y + 1 - n)) << " " << min(n, x + y - 1) << "\n";
	}

	return 0;
}