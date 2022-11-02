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
    int a[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += (long long)(i + 2) * a[i];
    }
    ans -= a[n - 1];
    cout << ans << endl;


    return 0;
}