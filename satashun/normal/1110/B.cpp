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
	int n, m, k; cin >> n >> m >> k;
	vi b(n);
	rep(i, n) {
		cin >> b[i];
	}

	int s = *max_element(ALL(b)) - *min_element(ALL(b)) + 1;

	vi vec;

	rep(i, n-1) {
		vec.pb(b[i+1] - b[i]);
	}

	sort(ALL(vec));
	reverse(ALL(vec));
	rep(i, k-1) {
		s -= (vec[i] - 1);
	}

	cout << s << endl;

	return 0;
}