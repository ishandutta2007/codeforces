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

const int INF = 1e8;

int n;
int d[200010];
int to[200010];

int main() {
    cin >> n;
    rep(i, n) {
	cin >> to[i];
	--to[i];
    }

    rep(i, n) d[i] = INF;

    priority_queue<pii, vector<pii>, greater<pii>> que;
    d[0] = 0;
    que.push(mp(0, 0));

    while (!que.empty()) {
	pii p = que.top(); que.pop();
	int v = p.se;
	if (p.fi > d[v]) continue;

	if (v > 0) {
	    if (d[v - 1] > d[v] + 1) {
		d[v - 1] = d[v] + 1;
		que.push(mp(d[v - 1], v - 1));
	    }
	}

	if (v < n - 1) {
	    if (d[v + 1] > d[v] + 1) {
		d[v + 1] = d[v] + 1;
		que.push(mp(d[v + 1], v + 1));
	    }
	}

	if (d[to[v]] > d[v] + 1) {
	    d[to[v]] = d[v] + 1;
	    que.push(mp(d[to[v]], to[v]));
	}
    }
    

    rep(i, n) printf("%d%c", d[i], i == n - 1 ? '\n' : ' ');

    return 0;
}