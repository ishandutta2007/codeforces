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
int a[64][64];

int main() {
    rep(i, 64) rep(j, 64) a[i][j] = -1;

    cin >> n;

    int c = 1;
    rep(i, n) {
	int d = n / 2 - abs(n / 2 - i);
	for (int j = n / 2 - d; j <= n / 2 + d; ++j) {
	    a[i][j] = c;
	    c += 2;
	}
    }

    c = 2;
    rep(i, n) {
	rep(j, n) {
	    if (a[i][j] == -1) {
		a[i][j] = c;
		c += 2;
	    }
	    if (j) printf(" ");
	    printf("%d", a[i][j]);
	}
	puts("");
    }
    return 0;
}