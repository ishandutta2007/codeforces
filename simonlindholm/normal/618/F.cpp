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
	vector<pii> a(N), b(N);
	rep(i,0,N) a[i].second = b[i].second = i+1;
	rep(i,0,N) cin >> a[i].first;
	rep(i,0,N) cin >> b[i].first;
	sort(all(a));
	sort(all(b));
	for (;;) {
		int i = 0, j = 0;
		ll cura = 0, curb = 0;
		vector<pii> seen(2*N+10, pii(-1, -1));
		seen[N] = pii(0, 0);
		for (;;) {
			if (cura < curb) {
				if (i == N) break;
				cura += a[i++].first;
			}
			else {
				if (j == N) break;
				curb += b[j++].first;
			}
			int ind = (int)(cura - curb + N);
			if (seen[ind].first != -1) {
				int i1 = seen[ind].first;
				int j1 = seen[ind].second;
				cout << i - i1 << endl;
				rep(k,i1,i) cout << a[k].second << ' ';
				cout << endl;
				cout << j - j1 << endl;
				rep(k,j1,j) cout << b[k].second << ' ';
				cout << endl;
				return 0;
			}
			seen[ind] = pii(i, j);
		}
		random_shuffle(all(a));
		random_shuffle(all(b));
	}
}