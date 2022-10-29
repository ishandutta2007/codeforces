#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-9;

typedef pair<int, int> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

int n;
const int N = 100 * 1000 + 50;
int a[N];

bool read() {
    
    scanf("%d", &n);
    forn (i, n)
        scanf("%d", &a[i]);

    return true;
}

const int B = 500;
map<int, int> cnt[B];
vector<int> x[B];

int id(int &pos) {
    int f = 0;
    while(pos >= x[f].size()) {
        pos -= x[f++].size();
    }
    return f;
}

int erase(int pos) {
    int f = id(pos);
    int res = x[f][pos];
    cnt[f][res]--;
    x[f].erase(x[f].begin() + pos);
    return res;
}

void insert(int pos, int v) {
    int f = id(pos);
    cnt[f][v]++;
    x[f].insert(x[f].begin() + pos, v);
}

void shift(int l, int r) {
    insert(l, erase(r));
}

int calc(int l, int r, int k) {
    int fl = id(l);
    int fr = id(r);
    int res = 0;
    if (fl == fr) {
        for (int i = l; i <= r; ++i)
            res += x[fl][i] == k;
        return res;
    }
    for (int i = fl + 1; i < fr; ++i)
        if (cnt[i].count(k))
            res += cnt[i][k];
    while(l < x[fl].size())
        res += x[fl][l++] == k;
    while(r >= 0)
        res += x[fr][r--] == k;
    return res;
}

void build() {
    int f = 0;
    forn (i, n) {
        x[f].pb(a[i]);
        cnt[f][a[i]]++;
        if (x[f].size() == B) {
            f++;
        }
    }
}

void restore() {
    int f = 0;
    int cur = 0;
    while(f < n) {
        forn (i, x[cur].size()) {
            a[f++] = x[cur][i];
        }
        cnt[cur].clear();
        x[cur++].clear();
    }
}

void rebuild() {
    restore();
    build();    
}

void solve() {
    
    build();

    int q;
    scanf("%d", &q);

    int T = B;
    
    int lastans = 0;

    forn (i, q) {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        l = (l + lastans - 1) % n + 1;
        r = (r + lastans - 1) % n + 1;
        l--, r--;
        if (l > r)
            swap(l, r);
        if (t == 1) {
            if (l == r)
                continue;
            shift(l, r);
            T--;
            if (T == 0) {
                T = B;
                rebuild();
            }
        } else {
            int k;
            scanf("%d", &k);
            k = (k + lastans - 1) % n + 1;
            lastans = calc(l, r, k);
            printf("%d\n", lastans);
        }
    }

}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    read();
    solve();

    return 0;
}