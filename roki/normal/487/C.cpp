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

const int N = 100005;
int n;

bool read() {
    return (cin >> n);    
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

li bp(li a, li b, int mod)
{
    if (b == 0)
        return 1;
    if (b & 1)
        return a * bp(a, b - 1, mod) % mod;
    return bp(a * a % mod, b >> 1, mod);
}

bool ok(vector<int> ans)
{
    if (ans.size() < n)
        return false;
    set<int> s;
    forn (i, n)
    {
        if (s.count(ans[i]))
            return false;
        s.insert(ans[i]);
    }
    return true;
}

void solve() {
    if (n == 1)
    {
        cout << "YES" << endl;
        cout << 1 << endl;
        return;
    }
    vector<int> ans;
    vector<bool> used(n + 1, false);

    ans.pb(1);
    li x = 1;
    forn (i, n - 2)
    {
        int k = n - i - 1;
        if (gcd(x, n) != 1)
            break;
        int y = bp(x, n - 2, n) * k % n;
        ans.pb(y);
        x = x * y % n;
    }
    ans.pb(n);
    if (ok(ans))
    {
        cout << "YES" << endl;
        forn (i, n)
            cout << ans[i] << endl;
        return;
    }
    ans.clear();
    ans.pb(1);
    x = 1;
    forn (i, n - 2)
    {
        int k = i + 2;
        if (gcd(x, n) != 1)
            break;
        int y = bp(x, n - 2, n) * k % n;
        ans.pb(y);
        x = x * y % n;
    }
    ans.pb(n);
    if (ok(ans))
    {
        cout << "YES" << endl;
        forn (i, n)
            cout << ans[i] << endl;
        return;

    }
    cout << "NO" << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

#ifdef TASK_NAME
    freopen(TASK_NAME ".in", "r", stdin);
    freopen(TASK_NAME ".out", "w", stdout);
#endif

    while(read())   
        solve();

    return 0;
}