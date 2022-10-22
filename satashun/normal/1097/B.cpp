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
	int n; cin >> n;
	vi a(n);
	rep(i, n) {
		cin >> a[i];
	}
	bool ok = false;
	rep(i, 1 << n) {
		int c = 0;
		rep(j, n) {
			if ((i >> j) & 1) {
				c += a[j];
			} else {
				c -= a[j];
			}
			c %= 360;
			if (c < 0) c += 360;
		}
		if (c == 0) {
			ok = true;
		}
	}
	puts(ok ? "YES" : "NO");
	return 0;
}