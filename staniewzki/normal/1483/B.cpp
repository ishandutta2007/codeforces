#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ssize(x) int(x.size())
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
	return o << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
	o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#ifdef DEBUG
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define debug(...) {}
#endif

struct Node {
	deque<pair<int, int>> vals;
	Node *prev, *next;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	REP(_t, t) {
		int n;
		cin >> n;
		vector<Node> nodes(n);
		REP(i, n) {
			int a;
			cin >> a;
			nodes[i].vals = {{a, i + 1}};
			int nxt = (i + 1) % n;
			nodes[i].next = &nodes[nxt];
			nodes[nxt].prev = &nodes[i];
		}

		auto del = [&](Node *ptr) {
			Node *l = ptr->prev, *r = ptr->next;
			l->next = r;
			r->prev = l;
		};

		vector<int> ans;
		Node *cur = &nodes[0];
		while(true) {
			bool end = false; 
			while(gcd(cur->vals.back().first, cur->next->vals.front().first) != 1) {
				if(cur == cur->next) {
					end = true;
					break;
				}
				if(cur->vals.size() >= cur->next->vals.size()) {
					auto &d = cur->next->vals;
					while(!d.empty()) {
						cur->vals.emplace_back(d.front());
						d.pop_front();
					}
					del(cur->next);
				}
				else {
					auto &d = cur->vals;
					while(!d.empty()) {
						cur->next->vals.emplace_front(d.back());
						d.pop_back();
					}
					del(cur);
					cur = cur->next;
				}
			}
			if(end) break;

			ans.emplace_back(cur->next->vals.front().second);
			cur->next->vals.pop_front();
			if(cur->next->vals.empty()) {
				if(cur == cur->next)
					break;
				del(cur->next);
			}
			cur = cur->next;
		}

		cout << size(ans) << " ";
		for(int i : ans)
			cout << i << " ";
		cout << "\n";

	}
}