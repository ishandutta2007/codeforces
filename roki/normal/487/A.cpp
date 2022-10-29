#define _USE_MATH_DEFINES

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
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()

typedef long long li;
typedef double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-15;

int c[3];

int dh, da, db;
int h, a, d;

bool read() {
    
    if (!(cin >> h >> a >> d))
        return false;
    
        cin >> dh >> da >> db;
    

    forn (i, 3)
        cin >> c[i];

    return true;
}

int calc(int h, int a, int b)
{
    if (db >= a)
        return INF;
    int dmg = a - db;
    int t1 = (dh + dmg - 1) / dmg;
    h -= t1 * (da - b);
    return max(0, -h + 1);
}

void solve() {
    int ans = INF;

    for (int atk = 0; atk <= 1000; ++atk)
        for (int def = 0; def <= 100; ++def)
            ans = min(li(ans), li(calc(h, a + atk, d + def)) * c[0] + atk * c[1] + def * c[2]);

    cout << ans << endl;
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

    while(read())   
        solve();

    return 0;
}