#include <bits/stdc++.h> // Tomasz Nowak
using namespace std;     // University of Warsaw
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ssize(x) int((x).size())
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

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string m;
	cin >> m;
	int n = ssize(m);
	vector<bool> in(n);
	REP(i, n)
		in[i] = bool(m[i] == '#');

	vector<pair<int, int>> blocks;
	for(int l = 0; l < n; ++l)
		if(in[l]) {
			int r = l;
			while(r + 1 < n and in[r + 1])
				++r;
			blocks.emplace_back(l, r);
			l = r;
		}
	debug(blocks);

	if(ssize(blocks) == 0) {
		cout << "0\n";
		return 0;
	}

	FOR(gap_end, 0, 6) {
		auto print_if_is_good = [&] {
			vector<int> gaps;	
			REP(b, ssize(blocks) + 1) {
				int start = (b == ssize(blocks) ? n + 1 : blocks[b].first);
				int prev_end = (b == 0 ? -2 : blocks[b - 1].second);
				int new_start = start - gap_end;
				debug(gap_end, b, start, prev_end, new_start);
				if(new_start <= prev_end + 1)
					return;
				int gap = new_start - prev_end - 2;
				debug(gap_end, b, gap);

				if(gap_end == 0) {
					if(gap != 0)
						return;
				}
				else if(gap_end == 1) {
					if(gap % 2 == 1)
						return;
					REP(gap1_cnt, gap / 2)
						gaps.emplace_back(1);
				}
				else {
					if(gap == 1)
						return;
					if(gap % 2 == 1) {
						gaps.emplace_back(2);
						gap -= 3;
					}
					assert(gap % 2 == 0);
					REP(gap1_cnt, gap / 2)
						gaps.emplace_back(1);
				}

				if(b != ssize(blocks))
					gaps.emplace_back(blocks[b].second - new_start + 1);
			}

			cout << ssize(gaps) << '\n';
			for(int g : gaps)
				cout << g << ' ';
			cout << '\n';
			exit(0);
		};
		print_if_is_good();
	}
	cout << "-1\n";
}