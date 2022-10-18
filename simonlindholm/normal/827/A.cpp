#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T>
auto addInterval(set<pair<T, T>>& is, T L, T R) {
	if (L == R) return is.end();
	auto it = is.lower_bound({L, R}), before = it;
	while (it != is.end() && it->first <= R) {
		R = max(R, it->second);
		before = it = is.erase(it);
	}
	if (it != is.begin() && (--it)->second >= L) {
		L = min(L, it->first);
		R = max(R, it->second);
		is.erase(it);
	}
	return is.insert(before, {L,R});
};

template <class T>
void removeInterval(set<pair<T, T>>& is, T L, T R) {
	if (L == R) return;
	auto it = addInterval(is, L, R);
	T r2 = it->second;
	if (it->first == L) is.erase(it);
	else (T&)it->second = L;
	if (R != r2) is.emplace(R, r2);
};


int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vector<string> strs;
	vector<vi> poss;
	int len = 0;
	rep(i,0,N) {
		string str;
		cin >> str;
		strs.push_back(str);
		int occ;
		cin >> occ;
		vi pos;
		rep(j,0,occ) {
			int p;
			cin >> p;
			--p;
			pos.push_back(p);
			len = max(len, p + sz(str));
		}
		poss.emplace_back(move(pos));
	}

	vi order(N);
	iota(all(order), 0);
	sort(all(order), [&](int i, int j) {
		return sz(strs[i]) > sz(strs[j]);
	});
	string output(len, '\0');
	set<pair<int, int>> is;
	is.insert(pii(len, len+1));
	is.insert(pii(-1, 0));
	trav(i, order) {
		string& s = strs[i];
		int l = sz(s);
		trav(p, poss[i]) {
			auto it = is.lower_bound(pii(p, -1));
			int left = p;
			int right = p + l;
			right = min(right, it->first);
			--it;
			left = max(left, it->second);
			rep(j,left,right) {
				assert(!output[j]);
				output[j] = s[j - p];
			}
			addInterval(is, p, p+l);
		}
	}
	trav(c, output) if (!c) c = 'a';
	cout << output << endl;
	exit(0);
}