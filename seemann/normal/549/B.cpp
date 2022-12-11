#include <cassert>
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

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 210;

int a[MAXN][MAXN];
int sum[MAXN];
int e[MAXN];

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n;
    cin >> n;
    FOR(i, n) {
        FOR(j, n) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    FOR(i, n)
        cin >> e[i];
    vector<int> ans;
    while (true) {
        int nm = -1;
        FOR(i, n) {
            if (sum[i] == e[i]) {
                nm = i;
                break;
            }
        }
        if (nm == -1)
            break;
        ans.pb(nm);
        FOR(i, n) {
            if (a[nm][i] == 1)
                sum[i]++;
        }
    }
    printf("%d\n", ans.size());
    for (auto i : ans) {
        printf("%d ", i + 1);
    }
    printf("\n");
    
    return 0;
}