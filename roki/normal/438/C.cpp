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
typedef pair<li, li> pt;

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

int n;
const int N = 205;

pt p[N];

bool read()
{
    if (!(cin >> n))
        return false;

    forn (i, n)
        cin >> p[i].x >> p[i].y;

    forn (i, n)
        p[i].x *= 2, p[i].y *= 2;

    return true;
}

bool ok[N][N];

int vprv(pt a1, pt a2, pt b2)
{
    a2.x -= a1.x, a2.y -= a1.y;
    b2.x -= a1.x, b2.y -= a1.y;

    li res = li(a2.x) * b2.y - li(a2.y) * b2.x; 
    if (res < 0)
        res = -1;
    if (res > 0)
        res = 1;

    return res;
}

bool intersect (pt a1, pt a2, pt b1, pt b2)
{
    if (min(a1.x, a2.x) > max(b1.x, b2.x))
        return false;
    if (min(a1.y, a2.y) > max(b1.y, b2.y))
        return false;
    if (min(b1.x, b2.x) > max(a1.x, a2.x))
        return false;
    if (min(b1.y, b2.y) > max(a1.y, a2.y))
        return false;

    if (vprv(a1, a2, b1) * vprv(a1, a2, b2) > 0)
        return false;
    if (vprv(b1, b2, a1) * vprv(b1, b2, a2) > 0)
        return false;

    return true;
}

li dp[N][N];
int mod = INF + 7;

void add(li &x, li val)
{
    x = (x + val) % mod;
}

li calc(int l, int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];

    if (!ok[l][r])
        return dp[l][r] = 0;

    int sum = 0;

    for (int i = l; i <= r; ++i)
        sum += abs(vprv(p[l], p[(l + 1) % n], p[i]));

    if (sum == 0)
        return dp[l][r] = 1;

    dp[l][r] = 0;

    for (int k = l + 1; k <= r - 1; ++k)
        add(dp[l][r], calc(l, k) * calc(k, r) % mod);

    return dp[l][r];
}

void solve() 
{
    forn (i, n)
        forn (j, n) 
            dp[i][j] = -1;

    forn (i, n)
    {
        ok[i][(i + 1) % n] = ok[(i + 1) % n][i] = true;
        forn (j, i - 1)
        {
            pt cur = mp((p[i].x + p[j].x) >> 1, (p[i].y + p[j].y) >> 1);
            int cnt = 0;
            forn (k, n)
                cnt += intersect(cur, mp(INF - 185165, INF + 12311), p[k], p[(k + 1) % n]);
            forn (k, n)
                cnt -= intersect(p[k], p[(k + 1) % n], cur, cur);
            
            forn (k, n)
                if (k != j && k != i)
                if (intersect(p[i], p[j], p[k], p[k]))
                    cnt <<= 1;

            forn (k, n)
                if (k != i && k != j && (k + 1) % n != i && (k + 1) % n != j)
                if (intersect(p[i], p[j], p[k], p[(k + 1) % n]))
                    cnt <<= 1;
        
            if (cnt & 1)
                ok[i][j] = ok[j][i] = true;
        }
    }

    cout << calc(0, n - 1) << endl;
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