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

int n, k;

pii ask(const V<int>& vec) {
	assert(vec.size() == k);
	printf("?");
	rep(i, k) printf(" %d", vec[i] + 1);
	puts("");
	fflush(stdout);
	int pos, a;
	scanf("%d %d", &pos, &a);
	--pos;
	return mp(a, pos);
}

void answer(int m) {
	printf("! %d\n", m);
	exit(0);
}

int main() {
	scanf("%d %d", &n, &k);
	V<pii> res;
	rep(i, k+1) {
		V<int> vec;
		for (int j = 0; j <= k; ++j) if (j != i) {
			vec.pb(j);
		}
		pii x = ask(vec);
		res.eb(x);
	}
	sort(ALL(res));
	int c=0;
	rep(j,res.size()) {
		if (res[j]==res[0]) {
			++c;
		} else {
			break;
		}
	}
	int m = k + 1 - c;
	answer(m);
	return 0;
}