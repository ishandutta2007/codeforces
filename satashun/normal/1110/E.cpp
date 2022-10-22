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

int main() {
	int n; scanf("%d", &n);
	vi a(n), b(n);
	rep(i, n) {
		scanf("%d", &a[i]);
	}
	rep(i, n) {
		scanf("%d", &b[i]);
	}

	bool ok = (a[0] == b[0] && a[n-1] == b[n-1]);

	vi d(n-1), e(n-1);
	rep(i, n-1) {
		d[i] = a[i+1] - a[i];
		e[i] = b[i+1] - b[i];
	}
	sort(ALL(d));
	sort(ALL(e));

	rep(i, n-1) {
		if (d[i] != e[i]) {
			ok = false;
		}
	}
	puts(ok ? "Yes" : "No");
	return 0;
}