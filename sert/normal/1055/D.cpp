#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)3004;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
const ll P1 = 337;
const ll P2 = 733;
bool D = false;

ll pw1[N], pw2[N];

vector<ll> getHash(const string &s) {
    vector<ll> res = {0};
    for (int i = 0; i < (int)s.length(); i++) {
        res.push_back((res[i] * P1 + s[i] - 'a' + 1) % MD);
    }
    return res;
}

void init() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < N; i++) {
        pw1[i] = pw1[i - 1] * P1 % MD;
        pw2[i] = pw2[i - 1] * P2 % MD;
    }
}

ll getHash(const vector<ll> &h, int l, int r) {
    return (h[r] - h[l] * pw1[r - l] + MD * MD) % MD;
}

string s[N * 2];
vector<ll> h[N * 2];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n * 2; i++) {
        cin >> s[i];
        h[i] = getHash(s[i]);
    }

    vector<int> st(n, -1);
    int len = -1;
    ll h1, h2;

    vector<bool> ok(n, false);
    int ff = -1;

    for (int i = 0; i < n; i++) {
        int a = -1;
        int b = -1;
        for (int j = 0; j < (int)s[i].length(); j++) {
            if (s[i][j] != s[i + n][j]) {
                if (a == -1) a = j;
                b = j;
            }
        }

        if (a == -1) {
            ok[i] = true;
            continue;
        }

        ll c1 = getHash(h[i], a, b + 1);
        ll c2 = getHash(h[i + n], a, b + 1);

        st[i] = a;

        if (len == -1) {
        	ff = i;
            len = b - a + 1;
            h1 = c1;
            h2 = c2;
        } else {
            if (b - a + 1 != len || h1 != c1 || h2 != c2) {
                cout << "NO\n";
                return;
            }
        }
    }

    while (true) {
    	bool ok1 = true;
    	char ch1 = '#', ch2 = '#';
    	for (int i = 0; i < n; i++) {
    		if (ok[i]) continue;
    		if (st[i] == 0) {
    			ok1 = false;
    			continue;
    		}
    		if (ch1 == '#') {
    			ch1 = s[i][st[i] - 1];
    			ch2 = s[i + n][st[i] - 1];
    		}
    		if (s[i][st[i] - 1] != ch1 || s[i + n][st[i] - 1] != ch2) ok1 = false;
    	}
    	if (ok1) {
    		for (int i = 0; i < n; i++) {
    			if (!ok[i]) st[i]--;
    		}
    		len++;
    	} else {
    		break;
    	}
    }

    while (true) {
    	bool ok1 = true;
    	char ch1 = '#', ch2 = '#';
    	for (int i = 0; i < n; i++) {
    		if (ok[i]) continue;
    		if (st[i] + len == (int)s[i].length()) {
    			ok1 = false;
    			continue;
    		}
    		if (ch1 == '#') {
    			ch1 = s[i][st[i] + len];
    			ch2 = s[i + n][st[i] + len];
    		}
    		if (s[i][st[i] + len] != ch1 || s[i + n][st[i] + len] != ch2) ok1 = false;
    	}
    	if (ok1) {
    		len++;
    	} else {
    		break;
    	}
    }

    for (int i = 0; i < n; i++) {
        if (ok[i]) {
            for (int j = 0; j + len <= (int)s[i].length(); j++) {
                if (getHash(h[i], j, j + len) == h1) {
                    cout << "NO\n";
                    return;
                }
            }
        } else {
            for (int j = 0; j < st[i]; j++) {
                if (getHash(h[i], j, j + len) == h1) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
    cout << s[ff].substr(st[ff], len) << "\n";
    cout << s[ff + n].substr(st[ff], len) << "\n";
}

int main() {
    init();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tst = 1;
    //scanf("%d", &tst);
    //cin >> tst;
#ifdef MADE_BY_SERT
    //freopen("input", "r", stdin);
    D = true;
	tst = 4;
	while (tst--) {
		solve();
	}
#else
    while (tst--) solve();
#endif
}