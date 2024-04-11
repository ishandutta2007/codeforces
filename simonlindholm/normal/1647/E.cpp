#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	vi a(N), p(N);
	rep(i,0,N) cin >> p[i], --p[i];
	rep(i,0,N) cin >> a[i], --a[i];
	vi indeg(N);
	rep(i,0,N) indeg[p[i]]++;
	int lost = 0;
	rep(i,0,N) if (indeg[i] == 0) lost++;
	int maxa = -1;
	rep(i,0,N) maxa = max(maxa, a[i]);
	assert((maxa - (N-1)) % lost == 0);
	int its = (maxa - (N-1)) / lost;
	vector<vi> jmp(30);
	jmp[0] = p;
	rep(it,1,30) {
		jmp[it].resize(N);
		rep(i,0,N) jmp[it][i] = jmp[it-1][jmp[it-1][i]];
	}
	vector<vi> ins(N);
	vi bucket(N);
	rep(i,0,N) {
		int at = i;
		for (int b = 0; b < 30; b++) if (its & (1 << b)) {
			at = jmp[b][at];
		}
		ins[at].push_back(i);
		bucket[i] = at;
	}

	vi b(N, -1);
	set<int> rem;
	rep(i,0,N) rem.insert(i);
	rep(i,0,N) if (sz(ins[i]) > 0) {
		int x = *min_element(all(ins[i]));
		b[x] = a[i];
		rem.erase(a[i]);
	}

	rep(i,0,N) if (b[i] == -1) {
		int minv = a[bucket[i]] + 1;
		auto it = rem.lower_bound(minv);
		assert(it != rem.end());
		b[i] = *it;
		rem.erase(it);
	}

	rep(i,0,N) cout << b[i]+1 << ' ';
	cout << endl;
}