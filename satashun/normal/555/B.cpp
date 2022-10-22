#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
#define MX 200010
#define eb emplace_back
typedef pair<ll, int> pli;

/*
struct ev{
    int tp, id;
    ll p;
    
    ev(){}
    ev(ll p, int id, int tp) : p(p), id(id), tp(tp){}

    bool operator<(const ev& a) const {
	if (p != a.p) return p < a.p;
	return tp < a.tp;
    }
};*/

int m, n;
pair<pair<ll, ll>, int> w[MX];
ll l[MX], r[MX];
pair<ll, int> a[MX];
int ans[MX];
//set<pair<ll, int> > sa;
//vector<ev> vec;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;

    rep(i, n) cin >> l[i] >> r[i];
    rep(i, n-1) {
	w[i] = mp(mp(l[i+1]-r[i], r[i+1]-l[i]), i);
	//vec.eb(w[i].fi, i, 0);
	//vec.eb(w[i].se, i, 1);
    }

    //sort(vec.begin(), vec.end());

    rep(i, m) {
	ll x;
	cin >> x;
	a[i] = mp(x, i);
    }

    sort(w, w + n);
    sort(a, a + m);

    //priority_queue<pli, vector<pli>, greater<pli> > que;

    int p = 0;

    set<pli> ss;

    rep(i, m) {
	ll x = a[i].fi;
	while (p < n && w[p].fi.fi <= x) {
	    ss.insert(mp(w[p].fi.se, w[p].se));
	    ++p;
	}

	auto it = ss.lower_bound(mp(x, -1));
	if (it == ss.end()) continue;

	ans[it->se] = a[i].se + 1;
	ss.erase(it);
    }

    rep(i, n-1) {
	if (!ans[i]) {
	    cout << "No" << endl;
	    return 0;
	}
    }

    cout << "Yes" << endl;
    rep(i, n-1) cout << ans[i] << (i==n-2?'\n':' '); 
/*
    for (const ev &e : vec) {
	if (e.tp == 0) ss.insert(mp(e.p, e.id));
	else {
	    
	}
    }

    rep(i, n-1) {
	que.push(mp(w[i].fi.se, w[i].se));

	if (que.empty()) {
	    cout << "No" << endl;
	    return 0;
	}

	bool ok = false;

	pli pp = que.top(); que.pop();

	if (a[p].fi > pp.fi) {
	    cout << "No" << endl;
	    return 0;
	}

	while (p < m && a[p].fi < w[i].fi) ++p;

	if (p == m) {
	    cout << "No" << endl;
	    return 0;
	}

	if (a[p].fi < pp.fi)
    }*/

    return 0;
}