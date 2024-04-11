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
	ll tx = 0, ty = 0;
	rep(i, n) {
		ll x, y;
		cin >> x >> y;
		tx += x;
		ty += y;
	}
	rep(i, n) {
		ll a, b;
		cin >> a >> b;
		tx += a;
		ty += b;
	}
	tx /= n; ty /= n;
	cout << tx << " " << ty << endl;
	return 0;
}