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

int n, m;
int lb = 0, ub = 1e8;

int main() {
	cin >> n >> m;

	while (ub - lb > 1) {
		int x = (lb + ub) / 2;
		int k = x / 6;
		int a = x / 2 - k;
		int b = x / 3 - k;
		bool ok = 0;

		if (a >= n && b >= m) {
			ok = 1;
		}

		int l = n - a;
		int r = b + k - m;
		if (l <= r) {
			if ((0 >= l && 0 <= r) || (k >= l && k <= r) || (0 <= l && r <= k)) {
				ok = 1;
			}
		}
		if (ok) ub = x;
		else lb = x;
	}
	cout << ub << endl;

	return 0;
}