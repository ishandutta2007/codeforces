#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:167772016")

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()

typedef long long li;
typedef long double ld;

typedef pair<int, int> pt;
#define ft first
#define sc second
#define x first
#define y second

const int INF = 1e9 + 6;
const li INF64 = 1e18;
const ld EPS = 1e-9;

#define sqr(n) ((n) * (n))

map<string, int> ans;

bool read() {

    return true;
}

void solve() {
    ans["polycarp"] = 1;
    int n;
    cin >> n;
    int res = 1;
    forn (i, n) {
        string a, b, c;
        cin >> a >> b >> c;

        forn (i, a.size())
            a[i] = tolower(a[i]);
        forn (i, c.size())
            c[i] = tolower(c[i]);

        ans[a] = ans[c] + 1;
        res = max(res, ans[a]);
    }

    cout << res << endl;
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