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
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const int MAXN = 1e5;

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }

    vector<int> s(n + 1);
    s[0] = -INF;
    forn(i, n) {
        int j = n - i - 1;
        s[i + 1] = max(s[i], a[j] - j);
    }

    ll ans = 0;

    int marks = 0;

    forn(i, n) {
        if (a[i] == marks) {
            marks++;
        } else if (s[n - i - 1] > -i - 1 + marks) {
            marks++;
        }

        ans += marks - a[i] - 1;
    }


    cout << ans << '\n';


    
    return 0;
}