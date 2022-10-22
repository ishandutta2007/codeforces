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
int u[4][110];
vi res;

int main() {
    memset(u, -1, sizeof(u));

    cin >> n >> m;
    
    rep(i, m) {
	if (i < n * 2) {
	    int p = (i & 1 ? 3 : 0);
	    int r = i / 2;
	    u[p][r] = i;
	} else {
	    int p = (i & 1 ? 2 : 1);
	    int r = (i - n * 2) / 2;
	    u[p][r] = i;
	}
    }

    rep(i, n) {
	for (int p : {1, 0, 2, 3}) if (u[p][i] != -1) res.pb(u[p][i] + 1);
    }

    rep(i, m) cout << res[i] << (i + 1 < m ? ' ' : '\n');

    return 0;
}