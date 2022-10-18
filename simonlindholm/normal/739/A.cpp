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
	int N, M;
	cin >> N >> M;
	int res = N+2;
	rep(i,0,M) {
		int a, b;
		cin >> a >> b;
		res = min(res, b - a + 1);
	}
	cout << res << endl;
	rep(i,0,N) cout << i % res << ' ';
	cout << endl;
	exit(0);
}