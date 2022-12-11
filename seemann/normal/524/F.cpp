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
const int MAXN = 1e6 + 100;
const int MAXA = 10;

char s[MAXN];
int b[MAXN];
int cnt[MAXN];
int pos[MAXN];
int c[MAXN];
int tp[MAXN], tc[MAXN];
int pb[MAXN], sb[MAXN];
bool good[MAXN];

char brc(char c) {
    if (c == 0)
        return '(';
    else
        return ')';
}

void print(int st, int n) {
    for (int i = st; i < n; ++i) {
        printf("%c", brc(s[i]));
    }
    for (int i = 0; i < st; ++i) {
        printf("%c", brc(s[i]));
    }
}

int main() {
//	freopen("f.in", "r", stdin);
	//freopen("f.out", "w", stdout);
	//freopen("", "w", stderr);
	scanf("%s", s);
//	cerr << s << '\n';
	int n = strlen(s);
	b[0] = 0;

    FOR(i, n) {
        if(s[i] == '(')
            s[i] = 0;
        else
            s[i] = 1;
    }
	FOR(i, n) {
	    if (s[i] == 0)
	        b[i + 1] = b[i] + 1;
	    else
	        b[i + 1] = b[i] - 1;
	}
	int sum = b[n];
	FOR(i, n) {
	    cnt[s[i]]++;
	}
	cnt[1] += cnt[0];
    for (int i = n - 1; i >= 0; --i) {
        pos[--cnt[s[i]]] = i;
    }
    int cl = 0;
    c[pos[0]] = 0;
    for (int i = 1; i < n; ++i) {
        if (s[pos[i]] != s[pos[i - 1]])
            cl++;
        c[pos[i]] = cl;
    }
    cl++;

    for (int lp = 0; (1 << lp) < n; ++lp) {
        FOR(i, n) {
            tp[i] = (pos[i] - (1 << lp) + n) % n;
        }
        FOR(i, cl)
            cnt[i] = 0;
        FOR(i, n) {
            cnt[c[tp[i]]]++;
        }
        FOR(i, cl - 1) {
            cnt[i + 1] += cnt[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            pos[--cnt[c[tp[i]]]] = tp[i];
        }
        tc[pos[0]] = 0;
        cl = 0;
        for (int i = 1; i < n; ++i) {
            int m1 = (pos[i] + (1 << lp)) % n;
            int m2 = (pos[i - 1] + (1 << lp)) % n;
            if (c[pos[i]] != c[pos[i - 1]] || c[m1] != c[m2])
                cl++;
            tc[pos[i]] = cl;
        }
        cl++;
        FOR(i, n) {
            c[i] = tc[i];
        }
    }
    /*
    FOR(i, n) {
        cerr << pos[i] << '\n';
    }
    cerr << sum << '\n';
    */
    int mb = 0;
    FOR(i, n + 1) {
        mb = min(mb, b[i]);
    }
//    cerr << mb << '\n';
    pb[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pb[i] = min(pb[i - 1], b[i]);
    }
    sb[0] = b[n];
    for (int i = 1; i <= n; ++i) {
        sb[i] = min(sb[i - 1], b[n - i]);
    }


    int ans = 0;
//    cerr << sum << '\n';
 //   cerr << sb[n] << '\n';
    if (sum >= 0) {
        FOR(i, n) {
            if (sb[n - i] >= b[i] && pb[i] + sum - b[i] >= 0)
                good[i] = true;
        }
        FOR(i, n) {
            if (good[pos[i]]) {
                ans = pos[i];
                break;
            }
        }
        print(ans, n);
        FOR(i, sum) {
            printf(")");
        }
    } else{
        FOR(i, n) {
            if (sb[n - i] - b[i] - sum >= 0 && pb[i] - b[i] >= 0)
                good[i] = true;
        }
        FOR(i, n) {
            if (good[pos[i]]) {
                ans = pos[i];
                break;
            }
        }
        FOR(i, abs(sum)) {
            printf("(");
        }
        print(ans, n);
    }
    printf("\n");
	return 0;
}