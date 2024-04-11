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

string s;

bool read() {
    cin >> s;
    return true;
}

void solve() {
    
    forn (k, s.size())
        forn (j, k)
        forn (i, j) {
            int cur = s[i] - '0';
            cur = cur * 10 + s[j] - '0';
            cur = cur * 10 + s[k] - '0';
            if (cur % 8 == 0) {
                cout << "YES" << endl;
                cout << cur << endl;
                return;
            }
        }

    forn (j, s.size())
        forn (i, j) {
            int cur = s[i] - '0';
            cur = cur * 10 + s[j] - '0';
            if (cur % 8 == 0) {
                cout << "YES" << endl;
                cout << cur << endl;
                return;
            }
        }
    
    forn (i, s.size())
        if (s[i] == '0' || s[i] == '8') {
            cout << "YES" << endl;
            cout << s[i] << endl;
            return;
        }

    cout << "NO" << endl;
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