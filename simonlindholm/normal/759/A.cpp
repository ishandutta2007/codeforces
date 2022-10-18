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
	vi p(N);
	rep(i,0,N) cin >> p[i], --p[i];
	vi seen(N);
	int cycles = 0;
	rep(i,0,N) if (!seen[i]) {
		int at = i;
		while (!seen[at]) seen[at] = 1, at = p[at];
		cycles++;
	}
	int res = cycles;
	if (res == 1) res = 0;

	vi b(N);
	int ct = 0;
	rep(i,0,N) cin >> b[i], ct += b[i];
	if (!(ct & 1)) res++;

	cout << res << endl;
	exit(0);
}