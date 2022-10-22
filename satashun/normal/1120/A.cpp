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

const int MX = 500010;

int cnt[MX];
int cur[MX];

int main() {
	int n, k, m, s;
	scanf("%d %d %d %d", &m, &k, &n, &s);
	V<int> a(m);
	rep(i, m) {
		scanf("%d", &a[i]);
		--a[i];
	}

	rep(i, s) {
		int b; scanf("%d", &b);
		--b; ++cnt[b];
	}

	int num = 0;
	rep(i, MX) if (cnt[i]) ++num;

	int r = 0;

	rep(i, m) {
		while (r < m) {
			if (r - i >= k && num == 0) {
				break;
			}			
			++cur[a[r]];
			if (cur[a[r]] == cnt[a[r]]) {
				--num;
			}
			++r;
		}

		dump(mp(i,r));
		if (num != 0) break;

		dump(mp(i,r));

		int can = (i / k) + (m - r) / k + 1; 
		if (can >= n) {
			V<int> vec;
			for (int j = i / k * k; j < i; ++j) {
				vec.pb(j);
			}
			
			V<int> use(m);
			int now = 0;
			for (int j = i; j < r; ++j) {
				if (cnt[a[j]] > 0) {
					use[j] = 1;
					now++;
					--cnt[a[j]];
				}
			}
			for (int j = i; j < r; ++j) {
				if (!use[j] && now < k) {
					use[j] = 1;
					now++;
				}
			}
			for (int j = i; j < r; ++j) {
				if (!use[j]) {
					vec.pb(j);
				}
			}	
			int sz = vec.size();
			printf("%d\n", sz);
			rep(j, sz) printf("%d%c", vec[j] + 1, j==sz-1?'\n':' ');
			return 0;		
		}

		if (cur[a[i]] == cnt[a[i]]) {
			++num;
		}
		dump(num);
		dump(cur[a[i]]);
		dump(cnt[a[i]]);
		--cur[a[i]];
	}
	puts("-1");

	return 0;
}