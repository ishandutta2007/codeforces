#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node {
	int lo, hi;
	Node *left = 0, *right = 0;
	ll count = 0;
	ll time = 0, sumTime = 0;
	Node(int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			left = new Node(lo, mid);
			right = new Node(mid, hi);
		}
	}
	void set(int ind, ll val) {
		if (ind < lo || ind >= hi) return;
		if (!left) {
			time = sumTime = val;
			count = 1;
		} else {
			left->set(ind, val);
			right->set(ind, val);
			sumTime = left->sumTime + right->sumTime;
			count = left->count + right->count;
		}
	}
	bool solve1();
	bool solve2();
};

int res;
ll T;

bool Node::solve1() {
	if (T <= 0) return false;
	if (T >= 2 * sumTime) {
		T -= 2 * sumTime;
		res += count;
		return true;
	}

	if (left) {
		if (!left->solve1()) return false;
		bool r = right->solve1();
		assert(!r);
	}
	return false;
}

int lim;
bool Node::solve2() {
	if (T <= 0) return false;
	if (res + count <= lim) {
		assert(T >= 2 * sumTime);
		T -= 2 * sumTime;
		res += count;
		return true;
	}
	if (res >= lim) {
		if (T >= sumTime) {
			T -= sumTime;
			res += count;
			return true;
		}
	}

	if (!left) return false;
	if (!left->solve2()) return false;
	if (!right->solve2()) return false;
	return true;
}

void solve() {
	int N, M;
	ll T;
	cin >> N >> M >> T;
	vector<ll> time(N);
	map<ll, vi> times;
	rep(i,0,N) {
		cin >> time[i];
		if (time[i] <= T) {
			times[time[i]].push_back(i);
		}
	}

	Node *tr = new Node(0, N);
	int res = 0;
	ll bestd = 1;
	trav(pa, times) {
		ll t = pa.first;
		trav(i, pa.second) {
			tr->set(i, t);
		}
		::T = T;
		::res = 0;
		tr->solve1();
		::lim = ::res / M * M;
		::T = T;
		::res = 0;
		tr->solve2();
		int myres = min(::res, ::lim + M);
		if (myres > res) {
			res = myres;
			bestd = t;
		}
	}
	cout << res << ' ' << bestd << endl;
}

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	rep(i,0,N) solve();
	_Exit(0);
}