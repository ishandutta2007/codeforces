#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n; cin >> n;
		vector<int> a(n * 2);
		int x[2] = {0};
		for (int i = 0; i < n * 2; i ++) {
			cin >> a[i];
			x[a[i] % 2] ++;
		}
		cout << (x[0]==x[1]?"Yes":"No") << endl;
	}
}