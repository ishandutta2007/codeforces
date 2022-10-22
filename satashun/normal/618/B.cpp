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

int p[64];
int n;
int a[64][64];

int main() {
    cin >> n;
    rep(i, n) {
	rep(j, n) {
	    cin >> a[i][j];
	}
    }

    rep(i, n) {
	p[i] = n;
	rep(j, n) if (j != i) p[j] = a[i][j];

	bool f = 1;
	rep(k, n) rep(l, n) if (k != l && min(p[k], p[l]) != a[k][l]) f = 0;
	if (f) {
	    rep(j, n) cout << p[j] << (j == n - 1 ? '\n': ' ');
	    return 0;
	}
    }
    return 0;
}