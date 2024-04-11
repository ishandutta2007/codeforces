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
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef double ld;

const int INF = 1e9;
const ld EPS = 1e-9;

typedef pair<int, int> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

const int N = 5000;
bool act[N];

int p[3];
int t[3];

int L = INF, R = -1;

int n;

bool read() {
    cin >> n;
    cin >> p[0] >> p[1] >> p[2];
    cin >> t[0] >> t[1];
    
    forn (i, n) {
        int l, r;
        cin >> l >> r;
        forn (i, r - l + 1)
            act[i + l] = true;
        L = min(L, l);
        R = max(R, r);
    }

    return true;
}

void solve() {
    
    t[1] += t[0];
    t[2] = INF;

    int ans = 0;
    int cur = 0;
    int curinactive = 0;

    for (int i = L; i < R; ++i) {
        if (!act[i]) {
            curinactive++;
            if (curinactive == t[cur])
                cur++;
        } else {
            curinactive = 0;
            cur = 0;
        }
        ans += p[cur];
    }

    cout << ans << endl;

}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    read();
    solve();

    return 0;
}