#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<ld, ld> pt;

#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ft first
#define sc second
#define x first
#define y second

const int INF = 1e9;
const ld EPS = 1e-10;

int x;

bool read()
{
    cin >> x;
    return true;
}

bool ok (int a)
{
    for (int i = 2; i * i <= a; ++i)
        if (a % i == 0)
            return true;
    return false;
}

void solve() 
{
    for (int i = 2; ; ++i)
        if (ok(i) && ok(x - i))
        {
            cout << i << ' ' << x - i << endl;
            return;
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