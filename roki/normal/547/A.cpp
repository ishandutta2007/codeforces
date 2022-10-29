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
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-9;

typedef pair<int, int> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

int m;
int h[2], a[2];
li x[2], y[2];

bool read() {
    cin >> m;
    forn (i, 2)
        cin >> h[i] >> a[i] >> x[i] >> y[i];
    return false;
}

void solve() {
    vector<int> c[2];
    int len[2];
    bool oncycle[2] = {false, false};
    int st[2];

    forn (i, 2) {
        c[i] = vector<int> (m, -1);
        int cur = h[i];
        int t = 0;
        while(c[i][cur] == -1) {
            c[i][cur] = t;
            cur = (cur * x[i] + y[i]) % m;
            t++;
        }
        st[i] = cur;
        len[i] = t - c[i][cur];
        oncycle[i] = c[i][cur] <= c[i][a[i]] && c[i][a[i]] <= t;
    }
    
    int cur[2] = {h[0], h[1]};

    int lb;
    li ct;

    forn (t, 3000000) {
        forn (i, 2)
            cur[i] = (x[i] * cur[i] + y[i]) % m;
        if (cur[0] == a[0] && cur[1] == a[1]) {
            cout << t + 1 << endl;
            return;
        }
        if (cur[0] == a[0])
            lb = cur[1], ct = t + 1;
    }

    if (!oncycle[0] || !oncycle[1]) {
        cout << -1 << endl;
        return;
    }

    int target = c[1][a[1]] - c[1][lb];
    if (target < 0) 
        target += len[1];
    forn (i, 1000000) {
        ct += len[0];
        target = (target - len[0]) % len[1];
        if (target < 0)
            target += len[1];
        if (target == 0) {
            cout << ct << endl;
            return;
        }
    }
    cout << -1 << endl;
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