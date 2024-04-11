#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<ctime>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

li n, k;
vector<li> a;

bool read()
{
    if(!(cin >> n >> k))
        return false;
    a.resize(n);
    forn (i, n)
    {
        li q, w, e, r;
        scanf("%d.%d.%d.%d\n", &q, &w, &e, &r);
        a[i] = r + 256 * e + 256 * 256 * w + 256 * 256 * 256 * q;
    }
}

void solve()
{
    li p = 0;
    for (li i = 31; i > 0; --i)
    {
        p += (li)1 << i;
        set<li> s;
        forn (j, n)
            s.insert(a[j] & p);
        if(s.size() == k)
        {
            cout << (p >> 24) << '.';
            p &= (1 << 24) - 1;
            cout << (p >> 16) << '.';
            p &= (1 << 16) - 1;
            cout << (p >> 8) << '.';
            p &= (1 << 8) - 1;
            cout << p << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    while(read())
    solve();
    return 0;
}