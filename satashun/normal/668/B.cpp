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

int n, q;
int mv[2];
int ans[1000010];

int main() {
    scanf("%d %d", &n, &q);

    while (q--) {
	int tp;
	scanf("%d", &tp);

	if (tp == 1) {
	    int x;
	    scanf("%d", &x);
	    mv[0] += x;
	    mv[1] += x;
	} else {
	    rep(i, 2) {
		if ((i + mv[i]) & 1) {
		    --mv[i];
		} else ++mv[i];
	    }
	}

	rep(i, 2) {
	    if (mv[i] < 0) mv[i] += n;
	    else if (mv[i] >= n) mv[i] -= n;
	}
    }

    rep(i, n) {
	int to = (i + mv[i & 1]) % n;
	ans[to] = i + 1;
    }

    rep(i, n) printf("%d%c", ans[i], (i == n - 1 ? '\n' : ' '));

    return 0;
}