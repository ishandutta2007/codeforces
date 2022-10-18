#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	int cnt = 0;
	vi re;
	rep(a,0,1000000) {
		int z = a / 5 + a / 25 + a / 125 + a / 625 + a / 3125 + a / 15625 + a / 78125 + a / 390625 + a / 1953125;
		if (z == N) {
			cnt++;
			re.push_back(a);
		}
	}
	cout << cnt << endl;
	trav(r, re) cout << r << ' ';
	cout << endl;
}