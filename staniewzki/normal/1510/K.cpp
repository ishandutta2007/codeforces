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

int inf = 100003;
int cnt, ans = inf;

void check(vector<int> &v, int &n) {
	REP(i, 2 * n) {
		if (v[i] != i)
			return;
	}
	ans = min(ans, cnt);
}

void move_one(vector<int> &v, int &n) {
	cnt++;
	REP(i, n)
		swap(v[2 * i], v[2 * i + 1]);
	check(v, n);
}

void move_n(vector<int> &v, int &n) {
	cnt++;
	REP(i, n)
		swap(v[i], v[i + n]);
	check(v, n);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(2 * n);
    REP(i, 2 * n) {
    	cin >> v[i];
    	v[i]--;
    }

    vector<int> vec(2 * n);
    REP(i, 2 * n)
    	vec[i] = v[i];
    cnt = 0;
    check(vec, n);
    
    REP(i, n) {
    	move_n(vec, n);
    	move_one(vec, n);
    }

    REP(i, 2 * n)
    	vec[i] = v[i];
    cnt = 0;
    REP(i, n) {
    	move_one(vec, n);
    	move_n(vec, n);
    }

    if (ans == inf)
    	ans = -1;
    cout << ans;
    return 0;
}