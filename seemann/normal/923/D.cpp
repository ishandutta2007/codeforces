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

struct Count {
    vector<int> bCount;
    vector<int> bLast;
    Count(const string& s) : bCount(s.length() + 1), bLast(s.length() + 1) {
        int n = s.length();
        bCount[0] = 0;
        bLast[0] = -1;
        forn(i, n) {
            bCount[i + 1] = bCount[i];
            bLast[i + 1] = bLast[i];

            if (s[i] == 'B' || s[i] == 'C') {
                bCount[i + 1]++;
                bLast[i + 1] = i;
            }
        }
    }

    int range(int l, int r) {
        return bCount[r] - bCount[l];
    }

    int getLast(int l, int r) {
        int lastPos = bLast[r];
        if (lastPos < l) {
            return r - l;
        } else {
            return r - lastPos - 1;
        }
    }
};


int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    Count sCount(s);
    Count tCount(t);

    int q;
    cin >> q;
    forn(i, q) {
        int sl, sr, tl, tr;
        cin >> sl >> sr >> tl >> tr;
        sl--, tl--;
        int sb = sCount.range(sl, sr);
        int tb = tCount.range(tl, tr);
        if (tb < sb || (tb - sb) % 2 != 0) {
            cout << 0;
            continue;
        }

        int lens = sCount.getLast(sl, sr);

        if (sb == 0 && tb > 0) {
            lens--;
        }

        int lent = tCount.getLast(tl, tr);

        if (lens < lent ||(tb == sb && ((lens - lent) % 3 != 0))) {
            cout << 0;
            continue;
        }
        cout << 1;
    }
    cout << '\n';

    return 0;
}