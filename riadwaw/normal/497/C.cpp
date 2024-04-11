//MIPT Ababahalamaha
#pragma comment (linker, "/STACK:128000000")
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long li;
typedef long long i64;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();


int main() {
#ifdef YA
	//assert(!s.empty());
	freopen("/Users/riad/ClionProjects/for-jhelper/input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	clock_t start = clock();
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout); 
	cin.tie(0);
#endif
	cout.sync_with_stdio(0);
	cout.precision(10);
	cout << fixed;
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		//++timer;
		solve();
	}
#ifdef YA
	cerr<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}

struct Actor {
	int l, r, k;
	int id;
};

bool byL(const Actor& l, const Actor& r) {
	return l.l < r.l || l.l == r.l && l.k > r.k;
}

struct byR {
	bool operator() (const Actor& l, const Actor& r) const {
		return l.r < r.r || l.r == r.r && l.id < r.id;
	}
};
void solve() {
	int n, m;
	cin >> n;
	vector<Actor> events(n);
	for (int i = 0; i < n; ++i) {
		cin >> events[i].l >> events[i].r;
		events[i].k = -1;
		events[i].id = i;
	}

	cin >> m;
	events.resize(n + m);
	for (int i = n; i < n + m; ++i) {
		cin >> events[i].l >> events[i].r >> events[i].k;
		events[i].id = i - n;
	}

	sort(all(events), byL);

	set<Actor, byR> actors;

	vi actor(n);

	for(const Actor& event: events) {
		if (event.k != -1) {
			actors.insert(event);
			continue;
		}
		//partia
		Actor tofind = {0, event.r, 0, -1};
		auto it = actors.lower_bound(tofind);
		if(it == actors.end()) {
			cout << "NO";
			return;
		}
		Actor copy = *it;
		actors.erase(it);
		copy.k--;
		if(copy.k) {
			actors.insert(copy);
		}

		actor[event.id] = copy.id;
	}
	cout << "YES\n";
	for(int i = 0; i < n; ++i) {
		cout << actor[i] + 1<< ' ';
	}


}