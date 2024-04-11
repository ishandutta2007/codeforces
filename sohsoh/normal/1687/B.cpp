#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

string s;
int n, m, last_ans;
vector<pll> edges;

inline int ask() {
	cout << "? " << s << endl;
	int x;
	cin >> x;
	return x;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		s.push_back('0');

	for (int i = 0; i < m; i++) {
		s[i] = '1';
		int w = ask();
		s[i] = '0';
		edges.push_back({w, i});
	}

	sort(all(edges));
	for (auto [w, ind] : edges) {
		s[ind] = '1';
		ll ans = ask();
		if (ans < last_ans + w) s[ind] = '0';
		else last_ans = ans;
	}

	cout << "! " << last_ans << endl;
	return 0;
}