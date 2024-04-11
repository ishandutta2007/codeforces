#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;
const int MOD = int(1e9) + 7;
const int N = 5050;

struct big {
    
    int len;
    int val[N];
    
};

int n;
big cur, ncur;
char s[N];
int len[N][N], pref[N][N], d[N][N], add[N][N], val[N][N];

inline void norm(int &a) {
    while (a >= MOD) {
        a -= MOD;
    }
}

inline bool good(int i, int j, int z) {
    if (pref[i][j + 1] >= j - i + 1) {
        return true;
    }
    int ni = i + pref[i][j + 1];
    int nj = j + 1 + pref[i][j + 1];
    return s[ni] < s[nj];
}

inline void calc(big &cur, int pos) {
    cur.len = 0;
    for (int i = n - 1; i >= pos; --i) {
        cur.val[cur.len++] = s[i] - '0';
    }
    int ptr = 0;
    cur.val[0] += len[pos][n - 1];
    while (cur.val[ptr] >= 2) {
        if (ptr + 1 >= cur.len) {
            cur.val[cur.len++] = 0;
        }
        cur.val[ptr + 1] += cur.val[ptr] / 2;
        cur.val[ptr] %= 2;
        ++ptr;
    }
}

inline bool cmp(big &a, big &b) {
    if (a.len != b.len) {
        return a.len < b.len;
    }
    int ptr = a.len - 1;
    while (ptr >= 0 && a.val[ptr] == b.val[ptr]) {
        --ptr;
    }
    if (ptr < 0) {
        return false;
    }
    return a.val[ptr] < b.val[ptr];
}

inline int value_of(big &a) {
    int res = 0;
    for (int i = a.len - 1; i >= 0; --i) {
        res = res * 2 + a.val[i];
        norm(res);
    }
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    gets(s);
    n = (int) strlen(s);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (s[i] != s[j]) {
                pref[i][j] = 0;
                continue;
            }
            pref[i][j] = 1;
            if (i + 1 < n && j + 1 < n) {
                pref[i][j] += pref[i + 1][j + 1];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            len[i][j] = inf;
            d[i][j] = 0;
            add[i][j] = 0;
            val[i][j] = inf;
        }
    }
    for (int i = 0; i < n; ++i) {
        len[0][i] = 1;
        d[0][i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        int cur_add = 0, cur_val = inf;
        for (int j = i; j < n; ++j) {
            cur_add += add[i][j];
            norm(cur_add);
            d[i][j] += cur_add;
            norm(d[i][j]);
            cur_val = min(cur_val, val[i][j]);
            len[i][j] = min(len[i][j], cur_val);
            int z = j + (j - i + 1);
            if (z >= n || !good(i, j, z)) {
                ++z;
            }
            if (z < n && s[j + 1] == '1') {
                add[j + 1][z] += d[i][j];
                norm(add[j + 1][z]);
                val[j + 1][z] = min(val[j + 1][z], len[i][j] + 1);
            }
        }
    }
    int sum_d = 0;
    for (int i = 0; i < n; ++i) {
        sum_d += d[i][n - 1];
        norm(sum_d);
    }
    cout << sum_d << endl;
    assert(len[0][n - 1] == 1);
    calc(cur, 0);
    for (int i = 1; i < n; ++i) {
        if (len[i][n - 1] == inf) {
            continue;
        }
        calc(ncur, i);
        if (cmp(ncur, cur)) {
            cur = ncur;
        }
    }
    cout << value_of(cur) << endl;
    return 0;
}