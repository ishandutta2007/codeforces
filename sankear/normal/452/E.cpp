#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL42
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif
#define next _next
#define prev _prev
#define hash _hash
#define rank _rank
#define link _link

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<double> tc;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(3e5) + 100;
const int MOD = int(1e9) + 7;

struct node {

    int len, link;
    map<int, int> next;

};

int sz, last;
bool used[6 * N];
int c1[6 * N], c2[6 * N], c3[6 * N];
char s[3 * N];
int addd[3 * N];
node v[6 * N];

inline void init() {
    sz = last = 0;
    v[0].len = 0;
    v[0].link = -1;
}

inline void add(int c) {
    int nlast = ++sz;
    v[nlast].len = v[last].len + 1;
    int p = last;
    while (p != -1 && v[p].next.count(c) == 0) {
        v[p].next[c] = nlast;
        p = v[p].link;
    }
    if (p == -1) {
        v[nlast].link = 0;
    } else {
        int q = v[p].next[c];
        if (v[p].len + 1 == v[q].len) {
            v[nlast].link = q;
        } else {
            int clone = ++sz;
            v[clone].len = v[p].len + 1;
            v[clone].link = v[q].link;
            v[clone].next = v[q].next;
            while (p != -1 && v[p].next.count(c) > 0 && v[p].next[c] == q) {
                v[p].next[c] = clone;
                p = v[p].link;
            }
            v[nlast].link = v[q].link = clone;
        }
    }
    last = nlast;
}

void dfs(int ver) {
    used[ver] = true;
    for (map<int, int>::iterator it = v[ver].next.begin(); it != v[ver].next.end(); ++it) {
            int c = it->fs, go = it->sc;
            if (!used[go]) {
            	dfs(go);
            }
            if (c < 26) {
                c1[ver] = (c1[ver] + c1[go]) % MOD;
                c2[ver] = (c2[ver] + c2[go]) % MOD;
                c3[ver] = (c3[ver] + c3[go]) % MOD;
            }
            if (c == 26) {
                c1[ver] = (c1[ver] + 1) % MOD;
            }
            if (c == 27) {
                c2[ver] = (c2[ver] + 1) % MOD;
            }
            if (c == 28) {
                c3[ver] = (c3[ver] + 1) % MOD;
            }
        }
    
}

int main() {
    init();
    int minLen = inf;
    for (int i = 0; i < 3; ++i) {
        gets(s);
        int len = strlen(s);
        minLen = min(minLen, len);
        for (int j = 0; j < len; ++j) {
            add(s[j] - 'a');
        }
        add(26 + i);
    }
    dfs(0);
    for (int i = 1; i <= sz; ++i) {
        int l = v[v[i].link].len + 1, r = v[i].len;
        int res = (1LL * c1[i] * c2[i]) % MOD;
        res = (1LL * res * c3[i]) % MOD;
        addd[l] = (addd[l] + res) % MOD;
        addd[r + 1] = (addd[r + 1] - res + MOD) % MOD;
    }
    int bal = 0;
    for (int i = 1; i <= minLen; ++i) {
        bal = (bal + addd[i]) % MOD;
        printf("%d ", bal);
    }
    puts("");
    return 0;
}