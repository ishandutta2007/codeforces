#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

const size_t buf_max = 100000;
char buf[buf_max] alignas(16);
size_t buf_ind = buf_max;

template <class T>
struct bump_allocator {
	typedef T value_type;
	bump_allocator() {}
	template <class U> bump_allocator(const U&) {}
	T* allocate(size_t n) {
		buf_ind -= n * sizeof(T);
		buf_ind &= ~(alignof(T) - 1);
		return (T*)(buf + buf_ind);
	}
	void deallocate(T*, size_t) {}
};


int a[100002];
int counts[100002];
int ccounts[100002];
int totCounts[100002];

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int N;
	cin >> N;
	rep(i,0,N) {
		cin >> a[i];
		totCounts[a[i]]++;
	}

	vi veryFrequent;
	rep(i,0,100002) {
		if (totCounts[i] >= 300)
			veryFrequent.push_back(i);
	}

	int Q;
	cin >> Q;
	vector<tuple<int,int,int>> que[1000];
	rep(i,0,Q) {
		int a, b;
		cin >> a >> b;
		--a;
		que[a / 300].emplace_back(b, a, i);
	}

	auto add = [&](int v) {
		v = a[v];
		int c = counts[v]++;
		--ccounts[c];
		++ccounts[c + 1];
	};
	auto remove = [&](int v) {
		v = a[v];
		int c = counts[v]--;
		--ccounts[c];
		++ccounts[c - 1];
	};

	/*
	priority_queue<pii> q;
	auto answer = [&]() {
		rep(i,1,300) {
			if (ccounts[i]) q.push(make_pair(-i, ccounts[i]));
		}
		trav(x, veryFrequent) {
			if (counts[x] >= 300) q.push(make_pair(-counts[x], 1));
		}

		int res = 0;
		while (q.size() > 1 || (q.size() == 1 && q.top().second > 1)) {
			int count = -q.top().first;
			int howmany = q.top().second;
			q.pop();
			while (!q.empty() && -q.top().first == count) {
				howmany += q.top().second;
				q.pop();
			}
			res += howmany * count;
			if (howmany > 1) {
				q.push(make_pair(-count * 2, howmany / 2));
				howmany %= 2;
			}
			if (howmany == 1) {
				int count2 = -q.top().first;
				int howmany2 = q.top().second;
				q.pop();
				res += count2;
				if (--howmany2)
					q.push(make_pair(-count2, howmany2));
				q.push(make_pair(-(count + count2), 1));
			}
		}
		while (!q.empty()) q.pop();
		return res;
	};
	*/

	vector<pii> vfadd;
	auto answer = [&]() {
		buf_ind = buf_max;
		forward_list<pii, bump_allocator<pii>> q;

		auto lastit = q.before_begin();
		int qs = 0;
		rep(i,1,300) {
			if (ccounts[i]) {
				lastit = q.insert_after(lastit, make_pair(i, ccounts[i]));
				qs++;
			}
		}

		vfadd.clear();
		trav(x, veryFrequent) {
			if (counts[x] >= 300) vfadd.emplace_back(counts[x], 1);
		}
		sort(all(vfadd));
		vfadd.emplace_back(-1, -1);
		rep(i,0,sz(vfadd)-1) {
			if (vfadd[i].first == vfadd[i+1].first) {
				vfadd[i+1].second += vfadd[i].second;
			}
			else {
				lastit = q.insert_after(lastit, vfadd[i]);
				qs++;
			}
		}

		lastit = q.insert_after(lastit, make_pair(100005, 0));
		qs++;

		auto insertIt = q.begin();
		auto ins = [&](int c, int v) {
			while (insertIt->first < c)
				++insertIt;
			if (insertIt->first == c) {
				insertIt->second += v;
			}
			else {
				pii old = *insertIt;
				*insertIt = make_pair(c, v);
				insertIt = q.insert_after(insertIt, old);
				qs++;
			}
		};

		int res = 0;
		while (qs > 2 || (qs == 2 && q.begin()->second > 1)) {
			auto beg = q.begin();
			int count = beg->first;
			int howmany = beg->second;
			res += howmany * count;
			if (howmany > 1) {
				ins(count * 2, howmany / 2);
				howmany %= 2;
			}
			if (howmany == 1) {
				auto it = beg;
				++it;
				int count2 = it->first;
				res += count2;
				ins(count + count2, 1);
				if (!--it->second) {
					--qs;
					q.pop_front();
				}
			}
			--qs;
			q.pop_front();
		}

		while (!q.empty())
			q.pop_front();
		return res;
	};

	int A = 0, B = 0;
	vi ans(Q);
	int lastqi = -1;
	rep(qa,0,1000) {
		sort(all(que[qa]));
		trav(pa, que[qa]) {
			int b, a, qi;
			tie(b, a, qi) = pa;
			if (a == A && b == B && 0) {
				ans[qi] = ans[lastqi];
			}
			else {
				while (a < A) add(--A);
				while (B < b) add(B++);
				while (A < a) remove(A++);
				while (b < B) remove(--B);
				ans[qi] = answer();
				lastqi = qi;
			}
		}
	}
	rep(i,0,Q)
		cout << ans[i] << '\n';
	exit(0);
}