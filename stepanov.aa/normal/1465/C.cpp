#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;


vector<int> x;
vector<int> y;
vector<int> fx;
vector<int> fy;
vector<bool> used;
int res;


int get_up(int i) {
	return fy[x[i]];
}


int get_right(int i) {
	return fx[y[i]];
}


void go(int i) {
	used[i] = true;
	if (x[i] == y[i]) {
		return;
	}
	res += 1;
	if (get_right(i) != -1){
		int j = i;
		while (true) {
			j = get_up(j);
			if (j == -1 || (used[j] && j != i)) {
				break;
			}
			res += 1;
			used[j] = true;
			if (j == i) {
				break;
			}
		}
	}
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		res = 0;
		x.resize(m);
		y.resize(m);
		fx.assign(n, -1);
		fy.assign(n, -1);
		used.assign(m, false);
		for (int i = 0; i < m; ++i) {
			cin >> x[i] >> y[i];
			--x[i];
			--y[i];
			fx[x[i]] = i;
			fy[y[i]] = i;
		}
		for (int i = 0; i < m; ++i) {
			if (!used[i]) {
				go(i);
			}
		}
		cout << res << "\n\n";
	}
	return 0;
}