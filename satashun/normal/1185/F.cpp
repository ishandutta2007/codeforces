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

const int MX = 512;

int cnt[MX], sum[MX];
vector<pii> mx[MX];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	rep(i, n) {
		int k; scanf("%d", &k);
		int mask = 0;
		rep(j, k) {
			int x; scanf("%d", &x);
			--x;
			mask |= (1 << x);
		}
		++cnt[mask];
	}

	rep(i, 512) {
		rep(j, 512) {
			if ((i & j) == j) {
				sum[i] += cnt[j];
			}
		}
	}
	rep(i, m) {
		int c, k; scanf("%d %d", &c, &k);
		int mask = 0;
		rep(j, k) {
			int x; scanf("%d", &x);
			--x;
			mask |= (1 << x);
		}
		mx[mask].eb(c, i);
	}

	rep(i, 512) sort(mx[i].begin(), mx[i].end());

	int maxi = -1, mini = -1;
	pii idx;

	rep(i, 512) {
		rep(j, i+1) {
			int mask = (i | j);
			if (i == j && mx[i].size() >= 2) {
				int num = sum[mask];
				if (num > maxi) {
					maxi = num;
					mini = mx[i][0].fi + mx[i][1].fi;
					idx = mp(mx[i][0].se, mx[i][1].se);
				} else if (num == maxi && mini > mx[i][0].fi + mx[i][1].fi) {
					mini = mx[i][0].fi + mx[i][1].fi;
					idx = mp(mx[i][0].se, mx[i][1].se);
				}
			} else if (i != j && mx[i].size() && mx[j].size()) {
				int num = sum[mask];
				if (num > maxi) {
					maxi = num;
					mini = mx[i][0].fi + mx[j][0].fi;
					idx = mp(mx[i][0].se, mx[j][0].se);
				} else if (num == maxi && mini > mx[i][0].fi + mx[j][0].fi) {
					mini = mx[i][0].fi + mx[j][0].fi;
					idx = mp(mx[i][0].se, mx[j][0].se);
				}				
			}
		}
	}

	cout << idx.fi + 1 << " " << idx.se + 1 << endl;

	return 0;
}