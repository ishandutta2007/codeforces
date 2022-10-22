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

const int maxn = 200010;

int dl[maxn], dr[maxn];

int main() {
	int n;
	scanf("%d", &n);
	vector<pii> a(n);
	rep(i, n) {
		scanf("%d", &a[i].fi);
		a[i].se = i;
	}
	sort(ALL(a));

	int ans = -1;

	if (n == 2) {
		puts("1");
		return 0;
	}

	dl[0] = -2;

	for (int i = 1; i < n; ++i) {
		if (dl[i-1] == -1) {
			dl[i] = -1;
		} else {
			int d = a[i].fi - a[i-1].fi;
			if (i == 1) {
				dl[i] = d;
			} else {
				if (dl[i-1] == d) {
					dl[i] = d;
				} else {
					dl[i] = -1;
				}
			}
		}
	}

	dr[n-1] = -2;

	for (int i = n-2; i >= 0; --i) {
		if (dr[i+1] == -1) {
			dr[i] = -1;
		} else {
			int d = a[i+1].fi - a[i].fi;
			if (i == n-2) {
				dr[i] = d;
			} else {
				if (dr[i+1] == d) {
					dr[i] = d;
				} else {
					dr[i] = -1;
				}
			}
		}
	}

	rep(i, n) {
		bool ok = false; 
		if (i == 0) {
			if (dr[i+1] != -1) {
				ok = 1;
			}
		} else if (i == n-1) {
			if (dl[i-1] != -1) {
				ok = 1;
			}
		} else {
			int d = a[i+1].fi - a[i-1].fi;
			bool okl = (i == 1 || dl[i-1] == d);
			bool okr = (i == n-2 || dr[i+1] == d);
			if (okl && okr) {
				ok = 1;
			}
		}
		if (ok) {
			cout << a[i].se + 1 << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}