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
	vi v(N+2);
	rep(i,0,N) cin >> v[i+1];
	v[0] = v[1];
	v[N+1] = v[N];
	vi dif(N+2);
	rep(i,0,N) if (v[i+1] != v[i] && v[i+1] != v[i+2]) dif[i+1] = 1;
	int from = -1;
	int steps = 0;
	rep(i,0,N+2) {
		if (!dif[i] && from != -1) {
			int len = i - from;
			steps = max(steps, (len+1)/2);
			int start = v[from-1];
			int end = v[i];
			rep(j,from,i)
				v[j] = (j - from >= len/2 ? end : start);
			from = -1;
		}
		else if (dif[i] && from == -1) from = i;
	}
	cout << steps << endl;
	rep(i,0,N) cout << v[i+1] << ' ';
	cout << endl;
}