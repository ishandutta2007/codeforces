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

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, a, b;
int v[15];

int pos = 0, q = 0;

int bans = 300;

int ans[10000], from[10000];

void chans()
{
    bans = q;
    forn (i, q)
        ans[i] = from[i];
}

double start;

void rec()
{
    if(q >= bans)
        return;
    if(pos == n && q < bans)
        chans();
    if((clock() - start) > 275)
        return;
    if(pos == n)
        return;
    pair<int, int> next[15];
    int sz = 0;
    for (int i = 1; i < n - 1; ++i)
    {   
        int p = 0;
        if(v[i] > 0)
            p += min(v[i], a);
        if(i > 0 && v[i - 1] > 0)
            p += min(v[i - 1], b);
        if(i < n - 1 && v[i + 1] > 0)
            p += min(v[i + 1], b);
        next[sz++] = mp(p, i);
    }
    sort(next, next + sz);
    for (int i = sz - 1; i >= max(sz - (pos > 6 ? 2 : 3), 0); --i)
    {
        if(next[i].first == 0)
            break;
        int c = pos;
        if(v[next[i].second] <= a && v[next[i].second] > 0)
            pos++;
        v[next[i].second] -= a;
        if(next[i].second > 0)
        {
            if(v[next[i].second - 1] <= b && v[next[i].second - 1] > 0)
                pos++;
            v[next[i].second - 1] -= b;
        }
        if(next[i].second < n - 1)
        {
            if(v[next[i].second + 1] <= b && v[next[i].second + 1] > 0)
                pos++;
            v[next[i].second + 1] -= b;
        }
        from[q++] = next[i].second;
        rec();
        q--;
        pos = c;
        v[next[i].second] += a;
        if(next[i].second > 0)
            v[next[i].second - 1] += b;
        if(next[i].second < n - 1)
            v[next[i].second + 1] += b;
    }
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    start = clock();
    cin >> n >> a >> b;
    forn (i, n)
    {
        cin >> v[i];
        v[i]++;
    }
    vector<int> add;
    while(v[0] > 0)
    {
        v[0] -= b;
        v[1] -= a;
        v[2] -= b;
        add.pb(2);
    }
    while(v[n - 1] > 0)
    {
        v[n - 1] -= b;
        v[n - 2] -= a;
        v[n - 3] -= b;
        add.pb(n - 1);
    }
    forn (i, n)
        if(v[i] <= 0)
            pos++;
    rec();
    cout << bans + add.size() << endl;
    forn (i, bans)
        cout << ans[i] + 1 << ' ';
    forn (i, add.size())
        cout << add[i] << ' ';
    return 0;
}