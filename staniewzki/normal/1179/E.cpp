#include<bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.ST << ", " << p.ND << ")";
}

template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto &e : x)
        	out << e << (&e == &*--x.end() ? "" : ", ");
	return out << '}';
}

template<class... Args> void dump(Args&&... args) {
	((cerr << args << ";  "), ...);
}
 
#ifdef DEBUG
#  define debug(x...) cerr << "[" #x "]: ", dump(x), cerr << "\n"
#else
#  define debug(...) false
#endif
 
template<class T> int size(T && a) { return (int) a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

mt19937 rng(2137);
int rd(int a) { return rng() % a; }

int n; 
LL L;

LL ask(int i, LL x) {
	cout << "? " << i + 1 << " " << x << endl;
	LL ret;
	cin >> ret;
	return ret;
}

LL search(int i, LL val, LL l, LL r) {
	while(l < r) {
		LL m = (l + r) / 2, a = ask(i, m);
		if(a == val) return m;
		else if(a < val) l = m + 1;
		else r = m - 1;
	}
	return l;
};

LL divide(vector<int> cur, LL val, LL l, LL r, vector<int> &low, vector<int> &high) {
	int goal_low = size(cur) / 2;
	int goal_high = size(cur) - goal_low;
	while(true) {
		int f = cur[rd(size(cur))];
		LL x = search(f, val, l, r);
		vector<int> left, mid, right;
		for(int i : cur) {
			LL a = ask(i, x);
			if(val < a) left.emplace_back(i);
			else if(val == a) mid.emplace_back(i);
			else right.emplace_back(i);
		}
		if(size(low) + size(left) <= goal_low) {
			for(int i : left)
				low.emplace_back(i);
			left.clear();
			while(size(mid) && size(low) < goal_low) {
				low.emplace_back(mid.back());
				mid.pop_back();
			}
		}
		if(size(right) + size(high) <= goal_high) {
			for(int i : right)
				high.emplace_back(i);
			right.clear();
			while(size(mid) && size(high) < goal_high) {
				high.emplace_back(mid.back());
				mid.pop_back();
			}
		}
		if(size(left)) cur = left;
		else if(size(right)) cur = right;
		else return x;
	}
}

vector<pair<LL, LL>> ans;
void solve(vector<int> cur, int done, LL l, LL r) {
	if(size(cur) == 1) {
		ans[cur.front()] = {l, r};
		return;
	}
	LL q = (L / n) * (done + size(cur) / 2);
	vector<int> low, high;
	LL p = divide(cur, q, l, r, low, high);
	solve(low, done, l, p);
	solve(high, done + size(low), p, r);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> L;
	ans.resize(n);

	vector<int> cur(n);
	REP(i, n) cur[i] = i;
	solve(cur, 0, 0, 1e18);

	cout << "!\n";
	for(auto &[l, r] : ans)
		cout << l << " " << r << "\n";
}