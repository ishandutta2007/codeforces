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

int N;

struct Node {
	vi ch;
	int ind;
	ll val;
	void root(int par);
	tuple<ll, ll, ll> solve() const;
};

vector<Node> no;

void Node::root(int par) {
	vi ch2;
	trav(c, ch) {
		if (c != par) ch2.push_back(c);
	}
	ch.swap(ch2);
	trav(c, ch)
		no[c].root(ind);
}

ll ans = 0;
tuple<ll, ll, ll> Node::solve() const {
	ll half = 0, one = 0, twohalf = 0, two = 0;
	vector<tuple<ll, ll, ll> > chans(sz(ch));
	typedef pair<ll, int> pli;
	array<pli, 3> opt1 = {pli{-100LL, -1}, pli{-100LL, -1}, pli{-100LL, -1}};
	array<pli, 3> opt2 = opt1, opt3 = opt2;
#define ADD(opt, v) do { \
		if (v > opt[0]) opt[2] = opt[1], opt[1] = opt[0], opt[0] = v; \
		else if (v > opt[1]) opt[2] = opt[1], opt[1] = v; \
		else if (v > opt[2]) opt[2] = v; \
	} while (0)
	rep(i,0,sz(ch)) {
		auto pa = no[ch[i]].solve();
		ADD(opt1, make_pair(get<0>(pa), i));
		ADD(opt2, make_pair(get<1>(pa), i));
		ADD(opt3, make_pair(get<2>(pa), i));
		chans[i] = pa;
	}
	static vector<bool> good;
	good.assign(sz(ch), false);
	rep(i,0,3) {
		if (opt1[i].second != -1) good[opt1[i].second] = true;
		if (opt2[i].second != -1) good[opt2[i].second] = true;
		if (opt3[i].second != -1) good[opt3[i].second] = true;
	}
	int g = 0;
	static vector<ll> halfs, ones, twohalfs;
	halfs.clear();
	ones.clear();
	twohalfs.clear();
	rep(i,0,sz(ch)) if (good[i]) {
		g++;
		halfs.push_back(get<0>(chans[i]));
		ones.push_back(get<1>(chans[i]));
		twohalfs.push_back(get<2>(chans[i]));
	}

	half = max(half, val);

	rep(i,0,g) {
		half = max(half, halfs[i] + val);
		one = max(one, ones[i]);
		rep(j,i+1,g) {
			one = max(one, halfs[i] + halfs[j] + val);
			two = max(two, ones[i] + ones[j]);
			rep(k,0,g) {
				if (k == i || k == j) continue;
				two = max(two, halfs[i] + halfs[j] + ones[k] + val);
			}
		}
		rep(k,0,g) {
			if (k == i) continue;
			two = max(two, halfs[i] + twohalfs[k] + val);
			twohalf = max(twohalf, halfs[i] + ones[k] + val);
		}
		twohalf = max(twohalf, ones[i] + val);
		twohalf = max(twohalf, twohalfs[i] + val);
	}

	// cerr << ind << ' ' << half << ' ' << one << ' ' << twohalf << ' ' << two << endl;

	one = max(one, half);
	two = max(two, twohalf);
	ans = max(ans, two);
	return make_tuple(half, one, twohalf);
}

int main() {
	cin.sync_with_stdio(false);
	cin >> N;
	no.resize(N);
	rep(i,0,N) no[i].ind = i;
	rep(i,0,N) cin >> no[i].val;
	rep(i,0,N-1) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		no[a].ch.push_back(b);
		no[b].ch.push_back(a);
	}

	no[0].root(-1);
	no[0].solve();
	cout << ans << endl;
}