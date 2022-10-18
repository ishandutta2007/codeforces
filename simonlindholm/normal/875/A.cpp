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
	int N;
	cin >> N;
	vi v;
	for (int a = max(N - 1000, 0); a <= N; a++) {
		ostringstream oss;
		oss << a;
		int sum = a;
		for (char c : oss.str()) {
			sum += c - '0';
		}
		if (sum == N) v.push_back(a);
	}
	cout << sz(v) << endl;
	trav(x, v) cout << x << endl;
	exit(0);
}