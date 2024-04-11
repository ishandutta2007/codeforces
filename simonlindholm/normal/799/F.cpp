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
	Node *l = 0, *r = 0;
	int lo, hi;
	ll val = 0, forb = 0, baseval;
	Node(int lo, int hi, int odd) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid, odd);
			r = new Node(mid, hi, odd);
			val = l->val + r->val;
		}
		else {
			if (odd == 2) baseval = 1;
			else baseval = lo*2 + odd;
			val = baseval;
		}
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L || forb) return 0;
		if (L <= lo && hi <= R) return val;
		return l->query(L, R) + r->query(L, R);
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			forb += x;
			val = forb ? 0 : (lo + 1 == hi ? baseval : l->val + r->val);
		}
		else {
			l->add(L, R, x), r->add(L, R, x);
			val = forb ? 0 : l->val + r->val;
		}
	}
};

struct Tr {
	int odd;
	Node *tr, *tr2;
	Tr(int odd) : odd(odd) {
		tr = new Node(0, 100010, 2);
		tr2 = new Node(0, 100010, odd);
	}
	int toi(int x) {
		if (odd != (x%2)) x++;
		return x/2;
	}
	ll query(int from, int to, int start) {
		from = toi(from);
		to = toi(to);
		ll count = tr->query(from, to);
		ll sum = tr2->query(from, to);
		return sum - (start-1) * count;
	}
	void forbid(int from, int to) {
// cerr << "forbid " << (odd ? "odd" : "even") << " " << from << ' ' << to << endl;
		from = toi(from);
		to = toi(to);
		tr->add(from, to, 1);
		tr2->add(from, to, 1);
	}
	void unforbid(int from, int to) {
// cerr << "unforbid " << (odd ? "odd" : "even") << " " << from << ' ' << to << endl;
		from = toi(from);
		to = toi(to);
		tr->add(from, to, -1);
		tr2->add(from, to, -1);
	}
};

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, M;
	cin >> N >> M;
	vector<pii> seg;
	vector<pair<int, pii>> ev;
	Tr eventree(0), oddtree(1);
	set<int> starts;
	starts.insert(M);
	rep(i,0,N) {
		int L, R;
		cin >> L >> R;
		--L;
		seg.emplace_back(L, R);
		ev.emplace_back(L, pii(i, 0));
		ev.emplace_back(R, pii(i, 1));
		starts.insert(L);

		if (L%2 == 0)
			oddtree.forbid(L, R);
		else
			eventree.forbid(L, R);
		if (L%2 == R%2)
			eventree.forbid(R, M),
			oddtree.forbid(R, M);
	}

	/*
	rep(i,0,M) {
		ll bfres = 0;
		rep(j,i+1,M+1) {
			bool any = false, fail = false;
			rep(k,0,N) {
				int lo = seg[k].first,
					hi = seg[k].second;
				lo = max(lo, i);
				hi = min(hi, j);
				if (lo < hi) {
					any = 1;
					if ((hi - lo) % 2 == 0) fail = 1;
				}
			}
			if (!any) fail = 1;
			if (!fail) bfres += j-i;
		}
		cout << bfres << ' ';
	}
	cout << endl;
	*/

	sort(all(ev));
	int eid = 0;
	multiset<int> active[2];
	ll res = 0;
	rep(i,0,M) {
		while (eid < sz(ev) && ev[eid].first == i) {
			int id = ev[eid].second.first;
			int type = ev[eid].second.second;
			int to = seg[id].second;
			if (type == 0) {
				active[to%2].insert(to);
				if (i%2 == 0)
					oddtree.unforbid(i, to);
				else
					eventree.unforbid(i, to);
				if (to%2 == i%2)
					eventree.unforbid(to, M),
					oddtree.unforbid(to, M);
			} else {
				auto it = active[to%2].find(to);
				active[to%2].erase(it);
			}
			eid++;
		}

		int canuntil = M;
		int mustdoodduntil = i;
		if (!active[i%2].empty()) {
			canuntil = *active[i%2].begin();
			mustdoodduntil = max(mustdoodduntil, *active[i%2].rbegin());
		}

		if (!active[(i+1)%2].empty()) {
			mustdoodduntil = max(mustdoodduntil, *active[(i+1)%2].rbegin());
		}

		int ji = i;
		if (active[i%2].empty() && active[(i+1)%2].empty()) {
			int j = *starts.lower_bound(i);
			mustdoodduntil = max(mustdoodduntil, j);
			ji = max(ji, j);
		}

// cerr << '!' << ji << ' ' << canuntil << ' ' << mustdoodduntil << endl;

		ll subres = 0;
		if (i % 2 == 0) {
			subres += eventree.query(ji, canuntil, i);
			subres += oddtree.query(mustdoodduntil, canuntil, i);
		}
		else {
			subres += eventree.query(mustdoodduntil, canuntil, i);
			subres += oddtree.query(ji, canuntil, i);
		}
		res += subres;
// cerr << '>' << i << ' ' << res << endl;
// cout << subres << ' ';
	}
// cout << endl;

	cout << res << endl;

	exit(0);
}