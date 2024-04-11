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
	rep(_,0,N) {
		string a, b;
		cin >> a >> b;
		vector<vi> match(sz(a), vi(sz(b)));
		vector<vi> rmatch(sz(a), vi(sz(b)));
		rep(i,0,sz(a)) {
			rep(j,i,sz(a)) {
				if (j - i >= sz(b)) break;
				if (a[j] != b[j - i]) break;
				match[j][j - i] = 1;
			}
			rep(j,i,sz(a)) {
				if (sz(b)-1 - (j - i) < 0) break;
				if (a[j] != b[sz(b)-1 - (j - i)]) break;
				rmatch[j][sz(b)-1 - (j - i)] = 1;
			}
		}

		rep(i,0,sz(a)) {
			rep(j,0,sz(b)) {
				if (match[i][j] && rmatch[i][j]) {
					cout << "YES" << endl;
					goto done;
				}
			}
		}

		cout << "NO" << endl;
done:;
	}
	exit(0);
}