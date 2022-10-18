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
	cin.exceptions(cin.failbit);
	string s;
	cin >> s;
	char next = 'a';
	trav(x, s) {
		if (x > next) {
			cout << "NO" << endl;
			return 0;
		}
		if (x == next) next++;
	}
	cout << "YES" << endl;
	exit(0);
}