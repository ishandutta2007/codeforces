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
typedef pair<int, int> pii;
typedef long double ld;

vector<int> vv[3][3];

int main() {
    int n;
    scanf("%d", &n);
    vector<int> p(n), a(n), b(n);
    forn(i, n) scanf("%d", &p[i]);
    forn(i, n) scanf("%d", &a[i]);
    forn(i, n) scanf("%d", &b[i]);

    forn(i, n) vv[a[i] - 1][b[i] - 1].push_back(p[i]);
    forn(i, 3) forn(j, 3) {
        sort(vv[i][j].begin(), vv[i][j].end());
        reverse(vv[i][j].begin(), vv[i][j].end());
    }

    int k, x;
    scanf("%d", &k);
    forn(q, k) {
        scanf("%d", &x);
        x--;
        int mc = 2e9, mi, mj = -1;
        forn(i, 3) forn(j, 3)
            if (i == x || j == x)
                if (!vv[i][j].empty()) {
                    if (vv[i][j].back() < mc) {
                        mc = vv[i][j].back();
                        mi = i, mj = j;
                    }
                }
        if (q) printf(" ");
        if (mj == -1) printf("-1");
        else {
            printf("%d", mc);
            vv[mi][mj].pop_back();
        }
    }
    printf("\n");
    return 0;
}