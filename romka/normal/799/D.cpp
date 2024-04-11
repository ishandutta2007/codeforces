#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sqr(x) (x) * (x)
template <class T> ostream& operator<<(ostream& out, const vector<T>& v) { forn(i, v.size()) { if (i) out << " "; out << v[i]; } return out; }
template <class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) { out << "{" << p.first << ", " << p.second << "}"; return out; }

typedef long long ll;
typedef pair<int, ll> pii;
typedef long double ld;

const int inf = 1e9;

int n, e[100010];
map<pii, int> mem;

int solve(int k, int l, int i) {
    if (k > l) swap(k, l);
    pii key(k, (ll)l * (n + 1LL) + i);
    if (mem.find(key) != mem.end()) return mem[key];
    int& res = mem[key];
    res = inf;
    if (k == 1 && l == 1) return res = 0;
    if (i == n) return res;

    if (k > 1) {
        res = min(res, solve((k + e[i] - 1) / e[i], l, i + 1) + 1);
    }
    if (l > 1) {
        res = min(res, solve(k, (l + e[i] - 1) / e[i], i + 1) + 1);
    }

    // printf("solve %d %d %d = %d\n", k, l, i, res);
    return res;
}

int solve(int a, int b, int h, int w) {
    return solve((h + a - 1) / a, (w + b - 1) / b, 0);
}

int main() {
    int a, b, h, w;
    scanf("%d %d %d %d %d", &h, &w, &a, &b, &n);
    forn(i, n) scanf("%d", &e[i]);
    sort(e, e + n);
    reverse(e, e + n);
    int r1 = min(solve(a, b, h, w), solve(b, a, h, w));
    if (r1 == inf) r1 = -1;
    printf("%d\n", r1);
    return 0;
}