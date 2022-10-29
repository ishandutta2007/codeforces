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

const int N = 100;
int a[N][N];

int n, k;
int mid;

bool read() {
    cin >> n >> k;
    mid = k / 2;
    return true;
}

void go(int x) {
    int func = INF;
    int px, pl, pr;
    forn (i, k) {
        int cnt = 0;
        int curfunc = 0;
        forn (j, x) {
            cnt += a[i][j];
            curfunc += abs(j - mid) + abs(i - mid);
        }
        if (cnt == 0) {
            if (curfunc < func) {
                func = curfunc;
                px = i, pl = 0, pr = x - 1;
            }
        }
        for (int j = x; j < k; ++j) {
            cnt += a[i][j] - a[i][j - x];
            curfunc += abs(j - mid) + abs(i - mid) - abs(j - x - mid) - abs(i - mid);
            if (cnt == 0) {
                if (curfunc < func) {
                    func = curfunc;
                    px = i, pl = j - x + 1, pr = j;
                }
            }
        }
    }
    if (func == INF)
        cout << -1 << endl;
    else {
        for (int i = pl; i <= pr; ++i)
            a[px][i] = 1;
        cout << px + 1 << ' ' << pl + 1 << ' ' << pr + 1 << endl;
    }
}

void solve() {
    
    forn (i, n) {
        int x;
        cin >> x;
        go(x);
    }

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