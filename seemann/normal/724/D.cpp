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


int cnt[310];
int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    
    cin.sync_with_stdio(false);
    cin.tie(0);
    int m;
    string s;
    cin >> m >> s;
    int n = s.length();
    for (char c = 'a'; c <= 'z'; ++c) {
        int last = -1;
        bool good = true;
        forn(i, s.length()) {
            if (s[i] > c)
                continue;
            if (last < i - m) {
                good = false;
                break;
            }
            last = i;
        }
        if (last < n - m) {
            good = false;
        }
        if (!good)
            continue;
        last = -1;
        int p = 0;
        int l = -1;

        while (p < n && l < n - m) {
            while (p < n && p <= l + m) {
                if (s[p] < c) {
                    l = p;
                } else if (s[p] == c) {
                    last = p;
                }
                p++;
            }
            if (l < n - m) {
                cnt[c]++;
                l = last;
            }
        }
        forn(i, s.length()) {
            if (s[i] >= c)
                continue;
            cnt[s[i]]++;
        }
        string ans;
        for (char x = 'a'; x <= 'z'; ++x) {
            forn(_, cnt[x]) 
                ans += x;
        }
        cout << ans << '\n';
        return 0;
    }

    return 0;
}