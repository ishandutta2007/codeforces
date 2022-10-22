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
int pm[7];
int d1, d2;
set<pii> ans;

int get(int x)
{
    if (!x) return 1;

    int u = 0;
    while (x) {
	x /= 7;
	++u;
    }
    return u;
}

int main() {
    cin >> n >> m;

    rep(i, 7) pm[i] = i;

    d1 = get(n - 1); d2 = get(m - 1);

    if (d1 + d2 > 7) {
	puts("0");
	return 0;
    }

    do {
	rep(i, 7) {
	    for (int j = i + 1; j < 7; ++j) {
		int a = 0, b = 0;
		for (int k = 0; k <= i; ++k) a = a * 7 + pm[k];
		for (int k = i + 1; k <= j; ++k) b = b * 7 + pm[k];

		if (get(a) < d1 && get(b) < d2) continue;
		if (get(a) <= d1 - 2 || get(b) <= d2 - 2) continue;

		if (a < n && b < m) {
		    bool u = 0;
		    for (int k = 0; k <= j; ++k) {
			if (pm[k] == 0) u = 1;
		    }

		    if (!(u && (get(a) < d1 || get(b) < d2))) {
			ans.insert(mp(a, b));
		    }
		}
	    }
	}

    } while(next_permutation(pm, pm + 7));

    cout << ans.size() << endl;
    return 0;
}