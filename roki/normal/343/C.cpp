#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, m;
li p[100010];
li a[100010];

bool read()
{
    if(!(cin >> n >> m))
        return false;
    forn (i, n)
        cin >> p[i];
    forn (i, m)
        cin >> a[i];
    return true;
}

bool f(li t)
{
    int l = 0;
    for (int i = 0; i < n; ++i)
    {
        li T = t;
        int nl = l;
        if(l < m && p[i] - a[l] > T)
            return false;
        if(l < m && a[l] < p[i])
            T -= (p[i] - a[l]) * 2;
        while(l < m && a[l] <= p[i])
            l++;
        while(l < m && a[l] - p[i] <= T)
            l++;
        int nxt = nl;
        T = t;
        while(nxt < m && (a[nxt] - p[i]) * 2 + p[i] - a[nl] <= T)
            nxt++;
        l = max(l, nxt);
    }
    return l == m;
}

void solve()    
{
    li l = 0, r = 1e18;
    while(r - l > 1)
    {
        li m = (r + l) >> 1;
        if(f(m))
            r = m;
        else
            l = m;
    }
    while(r > 0 && f(r - 1))
        r--;
    cout << r << endl;
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    while(read())
        solve();
    
    return 0;
}