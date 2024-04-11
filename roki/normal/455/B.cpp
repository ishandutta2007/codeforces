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
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-9;

typedef pair<int, int> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

int n, k;
const int N = 100000 + 50;
string s[N];

bool read() {
    cin >> n >> k;
    forn (i, n)
        cin >> s[i];
    return false;
}

int to[N][26];
int ft = 1;

void add(int v, string &s) {
    forn (i, s.size()) {
        if (to[v][s[i] - 'a'] == -1) {
            to[v][s[i] - 'a'] = ft;
            v = ft++;
        } else {
            v = to[v][s[i] - 'a'];
        }
    }
}

void init() {
    forn (i, N)
        forn (j, 26)
            to[i][j] = -1;
}

bool canwin[N];
bool canlose[N];

bool win(int v) {
    forn (i, 26)
        if (to[v][i] != -1) {
            if (!win(to[v][i]))
                return canwin[v] = true;
        }
    return canwin[v] = false;
}

bool lose(int v) {
    int cnt = 0;
    forn (i, 26)
        if (to[v][i] != -1) {
            cnt++;
            if (!lose(to[v][i]))
                return canlose[v] = true;
        }
    return canlose[v] = cnt == 0;
}

string ans[2] = {
    "First",
    "Second"
};


void solve() {

    init();

    forn (i, n)
        add(0, s[i]);

    win(0);
    lose(0);
    
    if (canlose[0] && canwin[0]) {
        cout << ans[0] << endl;
        return;
    }

    if (canwin[0]) {
        if (k & 1) {
            cout << ans[0] << endl;         
        } else {
            cout << ans[1] << endl;
        }
    } else {
        cout << ans[1] << endl;
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