#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

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

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

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
	int n, k;
	string s;
	cin >> n >> k >> s;

	string t = s;
	rep(i, n) if (i - k >= 0) {
		t[i] = t[i-k];
	}

	if (s <= t) {
		cout << n << endl;
		cout << t << endl;
		return 0;
	}

	int c = 1;

	for (int i = k - 1; i >= 0; --i) {
		int x = t[i] - '0';
		if (x + c < 10) {
			t[i] = '0' + x + c;
			break;
		}
		x = (x + c) % 10;
		c = 1;
		t[i] = '0' + x;
	}
	rep(i, n) if (i - k >= 0) {
		t[i] = t[i-k];
	}
	if (s <= t) {
		cout << n << endl;
		cout << t << endl;
		return 0;
	}	
	return 0;
}