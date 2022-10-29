#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef _DEBUG
#define endline endl
#else
#define endline "\n"
#endif

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define itr(x) x::iterator

typedef vector < int > vi;
typedef long long ll;

vector < ll > h, p;

bool can_fill(ll x)
{
#ifdef _DEBUG
    cerr << "try " << x << endline;
#endif
    int pos = 0;
    int cnt_h = sz(h);
    int cnt_p = sz(p);
    for (int i = 0; pos < cnt_p && i < cnt_h; ++i)
    {
        if (abs(p[pos] - h[i]) > x)
        {
            continue;
        }
        ll diff = 0LL;
        if (p[pos] >= h[i])
        {
            diff = x;
        }
        else
        {
            diff = max(max((x + p[pos] - h[i]) / 2, x - 2 * (h[i] - p[pos])), diff);
        }
        while (pos < cnt_p && p[pos] <= h[i] + diff)
        {
            ++pos;
        }
    }
    return (pos == cnt_p);
}

int
main()
{
    int n, m;
#ifndef _DEBUG
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
#else
    while ((cin >> n >> m))
    {
#endif
    h.resize(n);
    p.resize(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> p[i];
    }
    ll l_b = -1, r_b = 4 * 10000000000LL;
    while (l_b < r_b - 1)
    {
        ll m_b = (l_b + r_b) / 2;
        if (can_fill(m_b))
        {
            r_b = m_b;
        }
        else
        {
            l_b = m_b;
        }
    }
    cout << r_b << endline;
#ifdef _DEBUG
    }
#endif
    return 0;
}