#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	int ans = 0;
	int nt = 0;
	map<int, int> tow;
	int cur;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		if (tow.count(cur) > 0) {
			tow[cur]++;
			ans = max(ans, tow[cur]);
		}
		else {
			tow[cur] = 1;
			ans = max(ans, tow[cur]);
			nt++;
		}
	}
	cout << ans << " " << nt << endl;
	// cin >> N;
}