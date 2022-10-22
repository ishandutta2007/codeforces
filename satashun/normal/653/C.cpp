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
int a[150010];
int ac[150010];
set<pii> sw;

int main() {
    cin >> n;
    rep(i, n) cin >> a[i];

    vi cand;
    rep(i, n - 1) {
	if (i & 1) {
	    if (a[i] <= a[i + 1]) {
		cand.pb(i);
		cand.pb(i + 1);
	    } else {
		ac[i + 1] = 1;
	    }
	} else {
	    if (a[i] >= a[i + 1]) {
		cand.pb(i);
		cand.pb(i + 1);
	    } else {
		ac[i + 1] = 1;
	    }
	}
    }

    rep(i, n) ac[i + 1] += ac[i];

    sort(ALL(cand));
    cand.erase(unique(ALL(cand)), cand.end());

    if (cand.size() >= 10) {
	puts("0");
	return 0;
    }

    for (int p : cand) {
	rep(q, n) if (q != p) {
	    int s = p, t = q;
	    if (s > t) swap(s, t);
	    int num = (s > 0 ? ac[s - 1] : 0) + max(ac[n - 1] - ac[t + 1], 0) + max(ac[t - 1] - ac[s + 1], 0);

	    swap(a[s], a[t]);

	    if (s > 0) {
		if (s & 1) {
		    if (a[s] > a[s - 1]) {
			++num;
		    }
		} else {
		    if (a[s] < a[s - 1]) {
			++num;
		    }
		}
	    }

	    if (t < n - 1) {
		if (t & 1) {
		    if (a[t] > a[t + 1]) {
			++num;
		    }
		} else {
		    if (a[t] < a[t + 1]) {
			++num;
		    }
		}
	    }

	    if (s & 1) {
		if (a[s] > a[s + 1]) {
		    ++num;
		}
	    } else {
		if (a[s] < a[s + 1]) {
		    ++num;
		}
	    }

	    if (t != s + 1) {
		if (t & 1) {
		    if (a[t] > a[t - 1]) {
			++num;
		    }
		} else {
		    if (a[t] < a[t - 1]) {
			++num;
		    }
		}		
	    }

	    swap(a[s], a[t]);
	    
	    if (num == n - 1) {
		sw.insert(mp(s, t));
		sw.insert(mp(t, s));
	    }
	}
    }

    cout << sw.size() / 2 << endl;

    return 0;
}