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

int ask(vi v) {
	printf("?");
	rep(i, v.size()) printf(" %d", v[i]);
	puts("");
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}

int main() {
	vi a(100), b(100);

	rep(i, 100) {
		a[i] = i;
		b[i] = ((i + 1) << 7);
	}

	int p = ask(a);
	int q = ask(b);

	int u = p ^ q;

	rep(i, 100) {
		rep(j, 100) {
			if ((a[i] ^ b[j]) == u) {
				printf("! %d\n", a[i] ^ p);
				return 0;
			}
		}
	}

	return 0;
}