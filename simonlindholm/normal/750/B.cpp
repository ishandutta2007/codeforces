#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	int y = 0;
	rep(i,0,N) {
		int amt;
		string dir;
		cin >> amt >> dir;
		if ((dir == "East" || dir == "West") && (y == 0 || y == 20000)) {
			cout << "NO" << endl;
			return 0;
		}
		if (dir == "North") {
			y -= amt;
		}
		if (dir == "South") {
			y += amt;
		}
		if (y < 0 || y > 20000) {
			cout << "NO" << endl;
			return 0;
		}
	}
	if (y != 0) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	exit(0);
}