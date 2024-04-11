#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define pbk pop_back
#define all(x) (x).begin(), (x).end()
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define prev _prev
#define next _next
#define rank _rank
#define hash _hash

const int inf = 1e9;
const double pi = 4 * atan(1.0);
const double eps = 1e-9;
const int N = int(3e4) + 100;
const int MAX = int(1e8);

int n;
set<int> poss;
multiset<int> diffs;
int a[N];
int pref[N], suff[N];
map<int, int> pos;

inline void del_pos(int pos) {
    set<int>::iterator it = poss.find(pos);
    assert(it != poss.end());
    assert(*it == pos);
    set<int>::iterator next = it;
    ++next;
    if (it != poss.begin()) {
        set<int>::iterator prev = it;
        --prev;
        diffs.erase(diffs.find(a[pos] - a[*prev]));
        if (next != poss.end()) {
            diffs.erase(diffs.find(a[*next] - a[pos]));
            diffs.insert(a[*next] - a[*prev]);
        }
    } else {
        if (next != poss.end()) {
            diffs.erase(diffs.find(a[*next] - a[pos]));
        }
    }
    poss.erase(it);
}

inline void print() {
    for (int i = 0; i < n; ++i) {
        if (poss.find(i) == poss.end()) {
            printf("%d ", a[i]);
        }
    }
    puts("");
    for (int i = 0; i < n; ++i) {
        if (poss.find(i) != poss.end()) {
            printf("%d ", a[i]);
        }
    }
    puts("");
    exit(0);
}

inline void solve1(int pos) {
    if (pos > 0 && pref[pos - 1] == -1) {
        return;
    }
    if (pos + 1 < n && suff[pos + 1] == -1) {
        return;
    }
    poss.clear();
    poss.insert(pos);
    if (pos == 0) {
        if (suff[pos + 1] != -1) {
            print();
        }
        return;
    }
    if (pos == n - 1) {
        if (pref[pos - 1] != -1) {
            print();
        }
        return;
    }
    if (pref[pos - 1] == -42 && suff[pos + 1] == -42) {
        print();
    }
    if (pref[pos - 1] == -42) {
        if (a[pos + 1] - a[pos - 1] == suff[pos + 1]) {
            print();
        }
        return;
    }
    if (suff[pos + 1] == -42) {
        if (a[pos + 1] - a[pos - 1] == pref[pos - 1]) {
            print();
        }
        return;
    }
    if (pref[pos - 1] == suff[pos + 1] && a[pos + 1] - a[pos - 1] == pref[pos - 1]) {
        print();
    }
}

inline void check() {
    if (sz(poss) == 0) {
        return;
    }
    if (sz(poss) == 1) {
        print();
    }
    if (*diffs.begin() == *diffs.rbegin()) {
        print();
    }
}

inline void solve2(int p1, int p2) {
    poss.clear();
    diffs.clear();
    for (int i = 0; i < n; ++i) {
        poss.insert(i);
        if (i + 1 < n) {
            diffs.insert(a[i + 1] - a[i]);
        }
    }
    del_pos(p1);
    del_pos(p2);
    int cur = p2 + 1;
    int d = a[p2] - a[p1];
    check();
    for (;;) {
        int val = a[cur - 1] + d;
        if (abs(val) > MAX) {
            break;
        }
        int next = pos[val];
        if (next <= cur) {
            break;
        }
        cur = next;
        del_pos(cur - 1);
        check();
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        pos[a[i]] = i + 1;
    }
    pref[0] = -42;
    pref[1] = a[1] - a[0];
    for (int i = 2; i < n; ++i) {
        if (a[i] - a[i - 1] == pref[i - 1]) {
            pref[i] = pref[i - 1];
        } else {
            pref[i] = -1;
        }
    }
    suff[n - 1] = -42;
    suff[n - 2] = a[n - 1] - a[n - 2];
    for (int i = n - 3; i >= 0; --i) {
        if (a[i + 1] - a[i] == suff[i + 1]) {
            suff[i] = suff[i + 1];
        } else {
            suff[i] = -1;
        }
    }
    for (int i = 0; i < n; ++i) {
        solve1(i);
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            solve2(i, j);
        }
    }
    puts("No solution");
    return 0;
}