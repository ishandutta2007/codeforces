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
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>
#include <bitset>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int N = 5010;
int n, k;
int a[N];
vector<int> vals[21];

bool read() {

    if (!(cin >> n >> k))
        return false;

    forn (i, n)
        cin >> a[i];

    return true;
}
const int INF = 1e9;
bitset<1e7 + 1> ex;

void solve() {
        
    forn (i, n)
        ex[a[i]] = true;

    forn (i, n)
        forn (j, k + 1)
            vals[j].pb(a[i] * j);
    
    int q;
    cin >> q;
    forn (_, q) {
        int x;
        cin >> x;
        int ans = INF;
        for (int c1 = 1; c1 <= k; ++c1) {
            forn (i, vals[c1].size()) {
                int a = vals[c1][i];
                if (a == x)
                    ans = min(ans, c1);
                for (int c2 = 1; c2 + c1 <= k; ++c2) {
                    int left = x - a;
                    if (left % c2 != 0 || left < 0)
                        continue;
                    int b = left / c2;
                    if (b < 0 || b > 1e7)
                        continue;
                    if (ex[b])
                        ans = min(ans, c1 + c2);
                }
            }
        }
        if (ans == INF)
            ans = -1;
        cout << ans << endl;
    }

}

int main() {

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else

#ifdef TASK_NAME
    freopen(TASK_NAME ".in", "r", stdin);
    freopen(TASK_NAME ".out", "w", stdout);
#endif

#endif

    while (read())
        solve();
    
    return 0;
}