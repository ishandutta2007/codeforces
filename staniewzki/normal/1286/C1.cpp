#include<bits/stdc++.h>
using namespace std;
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.first << ", " << p.second << ")";
}
 
template<class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
	out << "{";
	for(auto it = a.begin(); it != a.end(); it = next(it))
		out << (it != a.begin() ? ", " : "") << *it;
	return out << "}";
}
 
void dump() { cerr << "\n"; }
template<class T, class... Ts> void dump(T a, Ts... x) {
	cerr << a << ", ";
	dump(x...);
}
 
#ifdef DEBUG
#  define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#  define debug(...) false
#endif
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
template<class T> int size(T && a) { return a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	auto ask = [&](int len) {
		cout << "? 1 " << len << endl;
		int k = len * (len + 1) / 2;
		vector<vector<string>> ret(len + 1);
		REP(i, k) {
			string str;
			cin >> str;
			ret[size(str)].emplace_back(str);
		}
		return ret;
	};


	if(n <= 2) {
		auto x = ask(1);
		if(n == 1)
			cout << "! " << x[1][0];
		if(n == 2) {
			auto y = ask(2);
			cout << "! " << x[1][0] << (y[1][0] == x[1][0] ? y[1][1] : y[1][0]);
		}
		cout << endl;
		return 0;
	}

	const int A = 26;
	auto count = [&](vector<string> vec) {
		vector<int> ret(A);
		for(auto &str : vec)
			for(char c : str)
				ret[c - 'a']++;
		return ret;
	};

	auto process = [&](int len, vector<vector<string>> all) {
		vector<vector<int>> ret(len + 1);
		auto ref = count(all[1]);
		auto used = ref;
		FOR(i, 1, (len - 1) / 2) {
			auto a = count(all[i + 1]);
			auto b = ref;
			for(int &x : b)
				x *= (i + 1);
			FOR(j, 1, i - 1) {
				for(int &x : ret[j])
					a[x] += 1 + i - j;
			}

			REP(j, A) REP(k, b[j] - a[j]) {
				ret[i].emplace_back(j);
				used[j]--;
			}
		}

		REP(j, A) REP(k, used[j])
			ret[(len + 1) / 2].emplace_back(j);
		return ret;
	};


	int l = (n + 1) / 2;
	auto h1 = ask(l);
	auto h2 = ask(l - 1);
	auto e1 = process(l, h1);
	auto e2 = process(l - 1, h2);

	debug(e1);
	debug(e2);

	vector<int> ans(n + 1);
	
	auto c1 = count(h1[1]);
	auto c2 = count(h2[1]);
	REP(j, A) if(c1[j] != c2[j])
		ans[l] = j;

	debug(ans);

	auto find = [&](vector<int> a, int b) {
		return (a[0] == b ? a[1] : a[0]);
	};

	FOR(i, 1, l / 2) {
		ans[i] = find(e1[i], ans[l + 1 - i]);
		if(size(e2[i]) == 2)
			ans[l - i] = find(e2[i], ans[i]);
	}

	debug(ans);

	auto h = ask(n);
	auto e = process(n, h);

	debug(e);

	FOR(i, 1, n / 2) {
		ans[n + 1 - i] = find(e[i], ans[i]);
		debug(i, e[i], ans[i], ans[n + 1 - i]);
	}

	cout << "! ";
	FOR(i, 1, n) cout << char(ans[i] + 'a');
	cout << endl;
}