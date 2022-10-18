#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void test() {
	int N, K;
	cin >> N >> K;
	vector<pii> chords;
	vi used(N*2);
	rep(i,0,K) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		if (x > y) swap(x, y);
		used[x] = 1;
		used[y] = 1;
		chords.push_back({x,y});
	}
	vi unused;
	rep(i,0,2*N) if (!used[i]) unused.push_back(i);
	rep(i,0,sz(unused)/2) {
		chords.push_back({unused[i], unused[i + sz(unused)/2]});
	}
	int res = 0;
	rep(i,0,sz(chords)) {
		rep(j,0,i) {
			auto a = chords[i];
			auto b = chords[j];
			if ((a.first < b.first && b.first < a.second && a.second < b.second) ||
				(b.first < a.first && a.first < b.second && b.second < a.second))
				res++;
		}
	}
	cout << res << endl;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	rep(i,0,N) {
		test();
	}
	exit(0);
}