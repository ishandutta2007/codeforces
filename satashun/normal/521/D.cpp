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

int num, n, m;
int a[100010];
int type[100010];
pii app[100010];
vector<pii> add[100010];
vector<pair<double, int>> vec;

int main() {
    scanf("%d %d %d", &num, &n, &m);

    rep(i, num) {
	scanf("%d", &a[i]);
	app[i] = mp(-1, -1);
    }

    rep(i, n) {
	int tp, id, b;
	scanf("%d %d %d", &tp, &id, &b);
	--tp; --id;
	type[i] = tp;

	if (tp == 0) {
	    app[id] = max(app[id], mp(b, i));
	} else if (tp == 1) {
	    add[id].pb(mp(b, i));
	} else {
	    vec.eb((double)b, i);
	}
    }

    rep(i, num) {
	int val = app[i].fi;

	if (val >= a[i]) {
	    add[i].eb(val - a[i], app[i].se);
	}

	sort(ALL(add[i]));
	reverse(ALL(add[i]));

	ll cs = a[i];

	for (pii p : add[i]) {
	    double rat = (1.0 + (double)p.fi / cs);
	    cs += p.fi;

	    vec.eb(rat, p.se);
	}
    }

    sort(ALL(vec));
    reverse(ALL(vec));

    while (vec.size() > m) vec.pop_back();

    printf("%d\n", (int)vec.size());

    bool f = 0;

    rep(tt, 3) {
	for (auto t : vec) if (type[t.se] == tt) {
	    if (f) printf(" ");
	    f = 1;
	    printf("%d", t.se + 1);
	}
    }

    puts("");

    return 0;
}