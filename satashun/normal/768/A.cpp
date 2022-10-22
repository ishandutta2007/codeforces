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

int n;
int a[100010];
int ret;

int main() {
	cin >> n;
	rep(i, n) cin >> a[i];
	int m = a[0], M = a[0];

	for (int i = 1; i < n; ++i) {
		m = min(m, a[i]);
		M = max(M, a[i]);
	}

	rep(i, n) {
		if (m < a[i] && M > a[i]) {
			++ret;
		}
	}

	cout << ret << endl;

	return 0;
}