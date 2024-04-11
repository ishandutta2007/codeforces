#ifdef LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>
#include <cmath>
#include <utility>
#include <ctime>
#include <climits>
#include <numeric>
#else
#include <bits/stdc++.h>
#endif

#define forn(i, n) for(int i = 0; i < (int) n; ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; ++i)
#define For(i, st, en) for(int i = (int)st; i <= (int)en; ++i)
#define clr(x) memset(x, 0, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;

/**
 * The code starts here.
 */

int t[100000];

int get(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res += t[r];
    }
    return res;
}

void add(int pos, int val) {
    for (; pos < 100000; pos |= pos + 1) {
        t[pos] += val;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("additive-class.in", "r", stdin);
    //freopen("additive-class.out", "w", stdout);
#endif
    //freopen("records-and-cycles.in", "r", stdin);
    //freopen("records-and-cycles.out", "w", stdout);

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        add(i, 1);
    }

    int q;
    cin >> q;

    int x = 0;
    int begin = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            cin >> p;

            if (2 * p > n) {
                if (!x) {
                    for (int i = p; i < n; ++i) {
                        add(p - (i - p) - 1 + begin, get(i + begin) - get(i - 1 + begin));
                    }
                    x = 1;
                    n = p;
                } else {
                    for (int i = 0; i < n - p; ++i) {
                        add(n - p + (n - p - i) - 1 + begin, get(i + begin) - get(i - 1 + begin));
                    }
                    x = 0;
                    begin += n - p;
                    n = p;
                }
            } else {
                if (!x) {
                    for (int i = 0; i < p; ++i) {
                        add(p + (p - i) - 1 + begin, get(i + begin) - get(i - 1 + begin));
                    }
                    begin += p;
                    n -= p;
                } else {
                    for (int i = n - p; i < n; ++i) {
                        add(n - p - (i - (n - p)) - 1 + begin, get(i + begin) - get(i - 1 + begin));
                    }
                    n -= p;
                }
            }
        } else {
            int l, r;
            cin >> l >> r;
            if (!x) {
                cout << get(r + begin - 1) - get(l + begin - 1) << "\n";
            } else {
                int a = n - r;
                int b = n - l;
                cout << get(b + begin - 1) - get(a + begin - 1) << "\n";
            }
        }
    }
    return 0;
}