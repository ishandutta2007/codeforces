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
int to[210];
int ord[210];
ll ret = 1;
int mdep;

int main() {
    cin >> n;
    rep(i, n) cin >> to[i], --to[i];

    rep(i, n) {
	int cur = 0, v = i;

	memset(ord, -1, sizeof(ord));

	while (true) {
	    ord[v] = cur++;
	    v = to[v];

	    if (ord[v] != -1) {
		ll sz = cur - ord[v];
		ret = ret / __gcd(ret, sz) * sz;
		mdep = max(mdep, ord[v]);
		break;
	    }
	}
    }

    if (ret < mdep) ret = (mdep + ret - 1) / ret * ret;
    cout << ret << endl;

    return 0;
}