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

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 1e5 + 100;

struct event {
    int x, tp;
    int n;
};

event e[MAXN];
int own[MAXN];
int owns[MAXN];
bool operator < (event a, event b) {
    if (a.x != b.x)
        return a.x < b.x;
    return a.tp < b.tp;
}

int main() {
	//freopen("d.in", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n, M, T;
	scanf("%d%d%d", &n, &M, &T);
	int m = 0;
	FOR(i, n) {
	    int h, mn, s;
	    scanf("%d:%d:%d", &h, &mn, &s);
	    int t = h * 60 * 60 + mn * 60 + s;
	    e[m].x = t;
	    e[m].n = i;
	    e[m++].tp = 1;

	    e[m].x = t + T;
	    e[m].n = i;
	    e[m++].tp = -1;
	}
	sort(e, e + m);
	/*
	FOR(i, m) {
	    cerr << e[i].n << ' ';
	}
	cerr << '\n';*/
	int mx = 0;
	int cur = 0;
	int u = 0;
	int last = -1;
	FOR(i, m) {
	    if (e[i].tp == 1) {
	        if (cur < M) {
	            last = u;
	            owns[u]++;
	            own[e[i].n] = u++;
	            cur++;
	            mx = max(mx, cur);
	        } else {
	            own[e[i].n] = last;
	            owns[last]++;
	        }
	    } else {
	        int curu = own[e[i].n];

            owns[curu]--;
            if (owns[curu] == 0) {
                cur--;
            }
	    }
//	    cerr << i << ' ' << cur << '\n';
	}
	if (mx < M) {
	    printf("No solution\n");
	} else {
	    printf("%d\n", u);
	    FOR(i, n) {
	        printf("%d\n", own[i] + 1);
	    }
	}



	return 0;
}