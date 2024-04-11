#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

li n, m;
li x, y;
li a, b;

inline void read()
{
    cin >> n >> m >> x >> y >> a >> b; 
}

bool f(li mid)
{
    li w = a * mid, h = b * mid;
    if(w > n || h > m)
        return false;
    return true;
}

li gcd(li q, li w)
{
    if(w == 0)
        return q;
    return gcd(w, q % w);
}

struct ans
{
    int a, b, c, d;
};
bool operator < (ans a, ans b)
{
    if(a.a != b.a)
        return a.a < b.a;
    if(a.b != b.b)
        return a.b < b.b;
    if(a.c != b.c)
        return a.c < b.c;
    return a.d < b.d;
}

inline void solve()
{
    li g = gcd(a, b);
    a /= g, b /= g;
    li l = 0, r = 1e9;
    while(r - l > 1)
    {
        li mid = (r + l) / 2;
        if(!f(mid))
            r = mid;
        else
            l = mid;
    }
    while(f(l + 1))
        l++;
    li lx = x - l * a / 2;
    if(lx + l * a > n)
        lx = n - l * a;
    li ly = y - l * b / 2;
    if(ly + l * b > m)
        ly = m - l * b;
    if(lx < 0)
        lx = 0;
    if(ly < 0)
        ly = 0;
    ld cx = (lx + lx + l * a) / 2.0;
    ld cy = (ly + ly + l * b) / 2.0;
    ld dist = sqrt((cx - x) * (cx - x) + (cy - y) * (cy - y));
    ans a1 = {lx, ly, lx + l * a, ly + l * b};
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
        {
            lx = x - (i + l * a) / 2;
            if(lx + l * a > n)
                lx = n - l * a;
            ly = y - (j + l * b) / 2;
            if(ly + l * b > m)
                ly = m - l * b;
            if(lx < 0)
                lx = 0;
            if(ly < 0)
                ly = 0;
            ans a2 = {lx, ly, lx + l * a, ly + l * b};
            ld ccx = (lx + lx + l * a) / 2.0;
            ld ccy = (ly + ly + l * b) / 2.0;
            ld cur = sqrt((ccx - x) * (ccx - x) + (ccy - y) * (ccy - y));
            if(fabs(dist - cur) < 1e-8 && a2 < a1 || cur < dist)
            {
                dist = cur;
                a1 = a2;
            }
        }

        cout << a1.a << ' ' << a1.b << ' ' << a1.c << ' ' << a1.d << endl;
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    read();
    solve();
    return 0;
}