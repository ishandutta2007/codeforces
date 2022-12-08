#include <iostream>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	int children[n+1];
	bool taken[n+1];

	for (int i = 0; i <= n; i++) {
		children[i] = 0;
		taken[i] = false;
	}
	int cur;
	map<int, int> par;
	for (int i = 1; i <= n; i++) {
		cin >> cur;
		par[i] = cur;
		if (cur > -1)
			children[cur]++;
	}
	int groups = 0;
	bool need = false;
	while (1) {
		need = false;
		bool off[n+1];
		for (int i = 1; i <= n; i++) {
			off[i] = false;
		}
		for (int i = 1; i <= n; i++) {
			if (taken[i] || off[i]) continue;
			if (children[i]==0) {

				taken[i] = true;
				need = true;
				if (par[i]!=-1) {
					children[par[i]]--;
					off[par[i]] = true;
				}
			}
		}
		if (!need) break;
		groups++;
	}
	cout << groups << endl;
	// cin >> n;

}