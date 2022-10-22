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

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

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

const int INF = TEN(9);

vector<int> Z_algo(const string &S) {
	vector<int> A(S.size());
	A[0] = S.size();
	int i = 1, j = 0;
	while (i < S.size()) {
		while (i+j < S.size() && S[j] == S[i+j]) ++j;
		A[i] = j;
		if (j == 0) { ++i; continue; }
		int k = 1;
		while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;
		i += k; j -= k;
	}
	return A;
}

int main() {
	int n, a, b; cin >> n >> a >> b;
	string s; cin >> s;

	V<int> dp(n + 1, INF);
	dp[0] = 0;

	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i-1] + a;

		string t = s.substr(0, i);
		reverse(ALL(t));

		dump(t);
		V<int> vec = Z_algo(t);
		V<int> cand;

		dump(vec);

		int mx = -1;
		for (int j = 1; j < i; ++j) {
			if (vec[j] != 0) {
				chmax(mx, min(vec[j],j));
			}
		}

		if (mx != -1) {
			for (int j = 1; j <= mx; ++j) {
				chmin(dp[i], dp[i-j] + b);
			}
		}
	}

	dump(dp);

	cout << dp[n] << endl;
	return 0;
}