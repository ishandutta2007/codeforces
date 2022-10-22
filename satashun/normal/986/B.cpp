#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

int main() {
	int n; cin >> n;
	vi p(n);
	rep(i, n) {
		cin >> p[i];
		--p[i];
	}

	int s = 0;

	vi vis(n);
	rep(i, n) {
		if (vis[i]) continue;
		int c = i;
		int a = 0;

		while (!vis[c]) {
			vis[c] = 1;
			c = p[c];
			a++;
		}
		s += (a-1);
		s %= 2;
	}

	bool ans;
	if (n % 2 == 0) {
		ans = s;
	} else {
		ans = s^1;
	}

	puts(!ans ? "Petr" : "Um_nik");

	return 0;
}