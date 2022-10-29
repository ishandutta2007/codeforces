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
typedef double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int INF = int(1e9) + 6;
const li INF64 = li(1e18);
const ld EPS = 1e-9;

#define sqr(n) ((n) * (n))

int n;
li m;

bool read() {
    cin >> n >> m;
    return true;
}

void solve() {
    vector<int> l;
    vector<int> r;
    int ft = 1;
    m--;
    while(ft <= n) {
        while (ft < n && 1LL << (n - ft - 1) <= m) {
            m -= 1LL << (n - ft - 1);
            r.pb(ft++);
        }
        if (ft <= n)
            l.pb(ft++);
    }
    forn (i, l.size())
        cout << l[i] << ' ';
    reverse(all(r));
    forn (i, r.size())
        cout << r[i] << ' ';
    cout << endl;
}

int main() {

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    read();
    solve();

    return 0;
}