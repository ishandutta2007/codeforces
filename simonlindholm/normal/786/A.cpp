#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N;
vi av, bv;

template<class F>
void reachable(int i, F f) {
	// trav(y, canreach[x]) f(y);
	bool bit = i&1;
	i >>= 1;
	if (bit) {
		trav(x, av) {
			int y = i - x;
			if (y < 0) y += N;
			f(2*y);
		}
	} else {
		trav(x, bv) {
			int y = i - x;
			if (y < 0) y += N;
			f(2*y+1);
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin >> N;

	int a, b;
	cin >> a;
	av.resize(a);
	rep(i,0,a) cin >> av[i];
	cin >> b;
	bv.resize(b);
	rep(i,0,b) cin >> bv[i];

	vi rem(2*N), losing(2*N), winning(2*N);
	queue<int> q;
	rep(i,0,N) rem[i*2] = a;
	rep(i,0,N) rem[i*2+1] = b;
	rem[0] = rem[1] = 0;
	q.push(0);
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		assert(!winning[x]);
		losing[x] = 1;
		reachable(x, [&](int y) {
			if (y != 0 && y != 1) {
				assert(!losing[y]);
				if (++winning[y] == 1) {
					reachable(y, [&](int z) {
						if (--rem[z] == 0) q.push(z);
					});
				}
			}
		});
	}

	auto st = [&](int x) {
		if (winning[x]) return "Win";
		if (losing[x]) return "Lose";
		return "Loop";
	};

	rep(i,1,N) cout << st(2*i) << ' ';
	cout << endl;

	rep(i,1,N) cout << st(2*i+1) << ' ';
	cout << endl;

	exit(0);
}