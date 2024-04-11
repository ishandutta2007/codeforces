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
#define dump(x) cerr << #x << " = " << (x) << endl
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

char ans[1010][1010];

int main() {
	int n; cin >> n;
	V<int> p(n), rp(n);
	rep(i, n) {
		cin >> p[i];
		--p[i];
		rp[p[i]] = i;
	}

	rep(i, n) rep(j, n) ans[i][j] = '.';

	{
		bool all = 1;
		rep(i, n) if (p[i] != i) {
			all = 0;
		}
		if (all) {
			printf("%d\n", n);
			rep(i, n) printf("%s\n", ans[i]);
			return 0;
		}
	}
	printf("%d\n", n-1);

	int l = -1; 
	rep(i, n) if (p[i] != i) {
		l = i;
		break;
	}

	//solve leftmost cycle

	V<int> used(n);

	int now = 0;
	{
		V<int> vec;
		int x = l;
		while (true) {
			vec.pb(x);
			used[x] = 1;
			x = rp[x];
			if (x == l) break;
		}
		int sz = vec.size();
		for (int i = sz - 1; i >= 1; --i) {
			if (vec[i-1] > vec[i]) {
				ans[now][vec[i-1]] = '/';
				ans[now][vec[i]] = '/';
			} else {
				ans[now][vec[i-1]] = '\\';
				ans[now][vec[i]] = '\\';
			}
			now++;
		}
	}

	//solve other cycles

	rep(i, n) if (p[i] != i && !used[i]) {
		V<int> vec;
		int x = i;
		while (true) {
			vec.pb(x);
			used[x] = 1;
			x = p[x];
			if (x == i) break;
		}

		int p = min_element(ALL(vec)) - vec.begin();
		int sz = vec.size();
		{
			V<int> nx;
			rep(i, sz) {
				nx.pb(vec[p]);
				p++;
				if (p == sz) p = 0;
			}
			vec = nx;
		}

		ans[now][l] = '/';
		ans[now][vec[0]] = '/';

		for (int i = 1; i < sz; ++i) {
			if (vec[i-1] < vec[i]) {
				ans[now][vec[i-1]] = '/';
				ans[now][vec[i]] = '/';
			} else {
				ans[now][vec[i-1]] = '\\';
				ans[now][vec[i]] = '\\';
			}
			now++;
		}
		ans[now][l] = '\\';
		ans[now][vec.back()] = '\\';
		now++;
	}

	rep(i, n) printf("%s\n", ans[i]);

	return 0;
}