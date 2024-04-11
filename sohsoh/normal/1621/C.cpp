#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int f = 0, P[MAXN], n;

inline int ask(int i) {
	cout << "? " << sep << i << endl;
	int x;
	cin >> x;
	f++;

	return x;
}

inline void cyc(int i) {
	int tf = f;
	deque<int> c;
	
	c.push_back(ask(i));
	while (true) {
		int x = ask(i);
		if (x == c.front()) break;
		c.push_back(x);
	}

	int sz = c.size();
	for (int i = 0; i < tf % sz; i++) {
		int x = c.back();
		c.pop_back();
		c.push_front(x);
	}

	vector<int> vec;
	while (!c.empty()) {
		vec.push_back(c.front());
		c.pop_front();
	}

	for (int i = 0; i < sz; i++)
		P[vec[i]] = vec[(i + 1) % sz];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < n + 10; i++) P[i] = 0;
		f = 0;
		cin >> n;

		for (int i = 1; i <= n; i++)
			if (!P[i])
				cyc(i);

		cout << "! ";
		for (int i = 1; i <= n; i++)
			cout << P[i] << sep;
		cout << endl;
	}
	return 0;
}