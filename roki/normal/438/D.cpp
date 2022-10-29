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
typedef pair<int, int> pt;

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

int n, m;
const int N = 100005;
int a[N];

bool read()
{
    if (scanf("%d%d", &n, &m) != 2)
        return false;

    forn (i, n)
        scanf("%d", &a[i]);

    return true;
}

int mVal[4 * N];
li sum[4 * N];

void build(int id, int l, int r)
{
    if (l == r)
    {
        mVal[id] = sum[id] = a[l];
        return;
    }

    int mid = (r + l) >> 1;
    int lc = 2 * id + 1, rc = 2 * id + 2;

    build(lc, l, mid);
    build(rc, mid + 1, r);

    mVal[id] = max(mVal[lc], mVal[rc]);
    sum[id] = sum[lc] + sum[rc];
}

li getSum(int id, int l, int r, int lf = 0, int rg = n - 1)
{
    if (lf == l && rg == r)
        return sum[id];
    int mid = (rg + lf) >> 1;

    li res = 0;

    if (mid >= l)
        res += getSum(2 * id + 1, l, min(r, mid), lf, mid);
    if (r >= mid + 1)
        res += getSum(2 * id + 2, max(mid + 1, l), r, mid + 1, rg);
    return res;
}

void setMod(int id, int l, int r, int x, int lf = 0, int rg = n - 1)
{
    if (mVal[id] < x)
        return;
    if (lf == rg)
    {
        a[lf] %= x;
        mVal[id] = a[lf];
        sum[id] = a[lf];
        return;
    }

    int mid = (lf + rg) >> 1;
    
    if (l <= mid)
        setMod(2 * id + 1, l, min(mid, r), x, lf, mid);
    if (r >= mid + 1)
        setMod(2 * id + 2, max(l, mid + 1), r, x, mid + 1, rg);

    mVal[id] = max(mVal[id * 2 + 1], mVal[id * 2 + 2]);
    sum[id] = sum[id * 2 + 1] + sum[id * 2 + 2];
}

void setVal(int id, int pos, int x, int lf = 0, int rg = n - 1)
{
    if (lf == rg)
    {
        a[lf] = x;
        mVal[id] = x;
        sum[id] = x;
        return;
    }
    int mid = (rg + lf) >> 1;
    if (pos <= mid)
        setVal(2 * id + 1, pos, x, lf, mid);
    else
        setVal(2 * id + 2, pos, x, mid + 1, rg);

    mVal[id] = max(mVal[id * 2 + 1], mVal[id * 2 + 2]);
    sum[id] = sum[id * 2 + 1] + sum[id * 2 + 2];
}

void solve() 
{
    build(0, 0, n - 1);
    forn (i, m)
    {
        int type;
        scanf("%d", &type);
        
        if (type == 1)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l--, r--;
            printf("%I64d\n", getSum(0, l, r));
        }
        if (type == 2)
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            l--, r--;
            setMod(0, l, r, x);
        }
        if (type == 3)
        {
            int l, x;
            scanf("%d%d", &l, &x);
            l--;
            setVal(0, l, x);
        }
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