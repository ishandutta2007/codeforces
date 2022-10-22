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

inline int ask(int a, int b) {
	cout << "? " << a << sep << b << endl;
	int x;
	cin >> x;
	return x;
}

inline int solve(vector<int> vec) {
	if (vec.size() == 1) return vec[0];
	else if (vec.size() == 2) return vec[ask(vec[0], vec[1]) - 1];

	int n = vec.size();
	vector<int> tvec;

	for (int i = 0; i < n; i += 4) {
		int x = ask(vec[i], vec[i + 2]);
		if (x == 0) {
			int y = ask(vec[i + 1], vec[i + 3]);
			if (y == 1) tvec.push_back(vec[i + 1]);
			else tvec.push_back(vec[i + 3]);
		} else if (x == 1) {
			int y = ask(vec[i], vec[i + 3]);
			if (y == 1) tvec.push_back(vec[i]);
			else tvec.push_back(vec[i + 3]);
		} else {
			int y = ask(vec[i + 1], vec[i + 2]);
			if (y == 1) tvec.push_back(vec[i + 1]);
			else tvec.push_back(vec[i + 2]);
		}
	}

	return solve(tvec);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> vec;
		for (int i = 0; i < (1 << n); i++)
			vec.push_back(i + 1);
	
		int ans = solve(vec);
		cout << "! " << ans << endl;
	}
	return 0;
}