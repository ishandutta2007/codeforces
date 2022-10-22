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
vi g[100010];
bool st[100010];
bool oned[100010];
int num[100010];

int main() {
    cin >> n;

    rep(i, n - 1) {
	int a, b;
	cin >> a >> b;
	--a; --b;
	g[a].pb(b);
	g[b].pb(a);
    }

    queue<int> que;

    rep(i, n) if (g[i].size() == 1) {
	que.push(i);
	st[i] = 1;
    }

    while (!que.empty()) {
	int v = que.front(); que.pop();
	for (int to : g[v]) {
	    if (g[to].size() <= 2) {
		if (!st[to]) {
		    st[to] = 1;
		    que.push(to);
		}
	    }
	}
    }

    rep(i, n) {
	for (int to : g[i]) {
	    if (st[to]) ++num[i];
	}
    }

    rep(i, n) {
	if (st[i]) oned[i] = 1;
	else {
	    if ((int)g[i].size() - min(num[i], 2) <= 1) oned[i] = 1;
	}
    }

    rep(i, n) if (!st[i]) {
	int adj = 0;

	for (int to : g[i]) if (!oned[to]) ++adj;

	if (adj > 2) {
	    puts("No");
	    return 0;
	}
    }

    puts("Yes");

    return 0;
}