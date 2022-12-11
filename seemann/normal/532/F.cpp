#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 2e5 + 1000;
const int MAXA = 250;
const ll MOD[2] = {1e9 + 7, 1e9 + 9};
const ll prime = 997;

struct mhash {
    ll h[2];
    bool operator != (const mhash & a) const {
        return h[0] != a.h[0] || h[1] != a.h[1];
    }
};

char s[MAXN], t[MAXN];
bool used[MAXA];
char pr[MAXA];
ll pw[2][MAXN];
mhash sh[26][MAXN];
mhash th[26][MAXN];

void getmhash(char * s, int n) {
    mhash zero;
    zero.h[0] = zero.h[1] = 0;
    
    for (char c = 'a' ; c <= 'z'; ++c) {
        int nc = c - 'a';
        sh[nc][0] = zero;
        FOR(t, 2) {
            FOR(i, n) {
                sh[nc][i + 1].h[t] = (sh[nc][i].h[t] * prime + ((s[i] == c)?(1):(0))) % MOD[t];
            }
        }
    }
}

mhash geth(mhash * h, int l, int r) {
    mhash res;
    FOR(t, 2) {
        res.h[t] = (h[r].h[t] - h[l].h[t] * pw[t][r - l] % MOD[t] + MOD[t]) % MOD[t];
    }
    return res;
}

int main() {
	//freopen("f.in", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(t, 2) {
	    pw[t][0] = 1;
	    FOR(i, n) {
	        pw[t][i + 1] = pw[t][i] * prime % MOD[t];
	    }
	}
	scanf(" %s %s", s, t);
	getmhash(t, m);
	FOR(i, 26)
	    FOR(j, m + 1)
	        th[i][j] = sh[i][j];
	getmhash(s, n);

    vector<int> fc, fp;
    clr(used);
    FOR(i, m) {
        if (!used[t[i]]) {
            used[t[i]] = true;
            fc.pb(t[i]);
            fp.pb(i);
        }
    }
    vector<int> ans;
    FOR(i, n - m + 1) {
        for (char c = 'a'; c <= 'z'; ++c)
            pr[c] = 0;
        bool flag = true;
        FOR(j, fc.size()) {
            char cc = fc[j];
            int cp = fp[j];
            char cs = s[i + cp];
            if (pr[cc] == 0 && pr[cs] == 0) {
                pr[cc] = cs;
                pr[cs] = cc;
                if (geth(sh[cc - 'a'], i, i + m) != geth(th[cs - 'a'], 0, m)) {
                    flag = false;
                    break;
                }
                if (cc != cs && geth(sh[cs - 'a'], i, i + m) != geth(th[cc - 'a'], 0, m)) {
                    flag = false;
                    break;
                }
            } else {
                if (pr[cc] != cs || pr[cs] != cc) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            ans.pb(i);
    }
    printf("%d\n", ans.size());
    for (auto p : ans) {
        printf("%d ", p + 1);
    }
    printf("\n");
	
	return 0;
}