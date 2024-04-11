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
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 1e5;

string tostr(int i) {
    string res = "aaaaaa";
    int pos = 5;
    while (i > 0) {
        res[pos] = char(i % 26 + 'a') ;
        i /= 26;
        pos--;
    }
    res[0] = toupper(res[0]);
    return res;
}

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, k;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    set<int> s;
    forn(i, n)
        s.insert(i);
    vector<int> p(n);
    forn(i, k - 1) {
        p[i] = i;
    }

    for (int i = k - 1; i < n; ++i) {
        string ss;
        cin >> ss;
        if (ss == "YES") {
            p[i] = i;
        }  else {
            p[i] = p[i - k + 1];
        }
    }
    for(auto i : p) {
   //     cout << i << ' ';
        cout << tostr(i) << ' ';
    }
    return 0;
}