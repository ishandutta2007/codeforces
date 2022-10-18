#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

typedef unsigned long long Hash;

const long long MOD = 1e9+7;

struct Number;

bool plus1(Number* x, Number** out);

struct Number {
	int length, bit;
	Hash hash;
	Number* left;
	Number* right;
	Number* next_;
	bool next_o;
	Number() : next_(0) {}
	bool leaf() { return length == 1; }
	bool next(Number** out) {
		if (!next_)
			next_o = plus1(this, &next_);
		*out = next_;
		return next_o;
	}
	long long sum();
	void chash() {
		if (leaf()) {
			hash = bit;
			return;
		}
		hash = left->hash * 12376823 * (1 + length) + right->hash;
		hash ^= (right->hash * 97961 * (4 + length) + left->hash) >> 2;
	}
};

static Number* zero;
map<int, Number*> zeroes;

long long Number::sum() {
	if (leaf())
		return bit;
	long long p2 = 1;
	for (int i = 0; i < right->length; ++i) {
		p2 *= 2;
		p2 %= MOD;
	}
	long long a = left->sum(), b = right->sum();
// cout << a << ' ' << p2 << ' ' << b << endl;
	return (a * p2 + b) % MOD;
}

bool plus1(Number* x, Number** out) {
	if (x->leaf()) {
		Number* ret = new Number;
		ret->length = 1;
		ret->bit = !x->bit;
		ret->chash();
		*out = ret;
		return x->bit == 1;
	}
	Number* ret = new Number;
	ret->left = x->left;
	ret->right = x->right;
	ret->length = x->length;
	*out = ret;
	if (!plus1(ret->right, &ret->right)) {
		ret->chash();
		return false;
	}
	if (!plus1(ret->left, &ret->left)) {
		ret->chash();
		return false;
	}
	ret->chash();
	return true;
}

bool add(Number* a, int dig, Number** out) {
	if (a->leaf())
		return a->next(out);
	Number* ret = new Number;
	ret->left = a->left;
	ret->right = a->right;
	ret->length = a->length;
	*out = ret;
	if (dig < a->right->length) {
		if (!add(ret->right, dig, &ret->right)) {
// cout << "A " << a->sum() << " + 2^" << dig << " = " << ret->sum() << endl;
			ret->chash();
			return false;
		}
		if (!plus1(ret->left, &ret->left)) {
// cout << "B " << a->sum() << " + 2^" << dig << " = " << ret->sum() << endl;
			ret->chash();
			return false;
		}
// cout << "C " << a->sum() << " + 2^" << dig << " = " << ret->sum() << endl;
		ret->chash();
		return true;
	}
	if (!add(ret->left, dig - a->right->length, &ret->left)) {
// cout << "D " << a->length << ' ' << a->sum() << " + 2^" << dig << " = " << ret->sum() << endl;
		ret->chash();
		return false;
	}
// cout << "E " << a->length << ' ' << a->left->length << ' ' << a->sum() << " + 2^" << dig << " = " << ret->sum() << endl;
	ret->chash();
	return true;
}

Number* fullAdd(Number* a, int dig) {
	while (a->length <= dig) {
		Number* large = new Number;
		large->length = a->length * 2;
		large->left = zeroes[a->length];
// if (!large->left) cerr << a->length << '.';
		large->right = a;
		large->chash();
		a = large;
	}
	Number* out;
	if (add(a, dig, &out)) {
		Number* large = new Number;
		large->length = a->length * 2;
		large->left = zeroes[a->length];
// if (!large->left) cerr << '.';
		large->right = a;
		large->chash();
		a = large;
		(void)add(a, dig, &out);
	}
	return out;
}

int compare(Number* a, Number* b) {
	if (a->hash == b->hash)
		return 0;
	if (a->length != b->length)
		return a->length < b->length ? -1 : 1;
	if (a->leaf())
		return a->bit < b->bit ? -1 : 1;
	int r = compare(a->left, b->left);
	if (r) return r;
	return compare(a->right, b->right);
}

struct Num {
	Number* n;
};
bool operator<(Num a, Num b) {
	return compare(a.n, b.n) < 0;
}

int main() {
	zero = new Number();
	zero->length = 1;
	zero->bit = 0;
	zero->chash();
	Number* zero2 = zero;
	zeroes[1] = zero;
	for (int i = 0; i < 30; ++i) {
		Number* zero3 = new Number;
		zero3->length = zero2->length * 2;
		zero3->left = zero2;
		zero3->right = zero2;
		zero3->chash();
		zeroes[zero3->length] = zero3;
		zero2 = zero3;
	}
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int> > > adj(N);
	for (int i = 0; i < M; ++i) {
		int u, v, x;
		cin >> u >> v >> x;
		adj[u-1].emplace_back(v-1, x);
		adj[v-1].emplace_back(u-1, x);
	}
	int s, t;
	cin >> s >> t;
	--s, --t;
	set<pair<Num, pair<int, int> > > di;
	Num zeron = {zero};
	di.insert(make_pair(zeron, make_pair(s, -2)));
	vector<int> froma(N, -1);
	while (!di.empty()) {
		pair<Num, pair<int, int> > pa = *di.begin();
		di.erase(di.begin());
		Number* n = pa.first.n;
		int ind = pa.second.first;
		int from = pa.second.second;
		if (froma[ind] != -1)
			continue;
		froma[ind] = from;
		if (ind == t) {
			cout << n->sum() << endl;
			vector<int> path;
			path.push_back(t);
			int prev = ind;
			while (prev != s) {
				prev = froma[prev];
				path.push_back(prev);
			}
			reverse(path.begin(), path.end());
			cout << path.size() << endl;
			for (int x : path)
				cout << (x + 1) << ' ';
			cout << endl;
			return 0;
		}
		for (pair<int, int> ad : adj[ind]) {
			int to = ad.first;
			int bit = ad.second;
			Num tot = {fullAdd(n, bit)};
// cout << n->sum() << " + 2^" << bit << " = " << tot.n->sum() << endl;
			di.insert(make_pair(tot, make_pair(to, ind)));
		}
	}
	cout << -1 << endl;
	return 0;
}