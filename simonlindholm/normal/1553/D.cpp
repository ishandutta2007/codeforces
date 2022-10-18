#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool solve(string a, string b) {
	int at = 0, wrong = 0;
	for (char c : a) {
		if (wrong) {
			wrong = 0;
		} else {
			if (at < sz(b) && c == b[at]) {
				at++;
			} else wrong = 1;
		}
	}
	return (at == sz(b) && !wrong);
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	string a, b;
	rep(i,0,N) {
		cin >> a >> b;
		if (solve(a, b) || solve(a.substr(1), b)) cout << "YES\n";
		else cout << "NO\n";
	}
	exit(0);
}