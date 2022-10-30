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
    return cin >> s;
}

void solve() {

    forn (i, s.size())
        s[i] = tolower(s[i]);

    int ab = -1, ba = -1;

    forn (i, s.size() - 1) {
        if (s[i] == 'a' && s[i + 1] == 'b' && ab == -1)
            ab = i;
        if (s[i] == 'b' && s[i + 1] == 'a')
            ba = i;
    }

    if (ab != -1 && ba != -1 && ab + 1 < ba) {
        cout << "YES" << endl;
        return;
    }

    ab = -1, ba = -1;

    forn (i, s.size() - 1) {
        if (s[i] == 'a' && s[i + 1] == 'b')
            ab = i;
        if (s[i] == 'b' && s[i + 1] == 'a' && ba == -1)
            ba = i;
    }

    if (ab != -1 && ba != -1 && ba + 1 < ab) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    while(read())
        solve();

    return 0;
}