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

bool g[200000];

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int q[100000], w[100000];
    forn (i, n)
    {
        int a;
        cin >> a;
        q[i] = a;
        v.pb(mp(a, i));
    }
    forn (i, n)
    {
        int a;
        cin >> a;
        w[i] = a;
        v.pb(mp(a, i));
    }
    int m;
    cin >> m;
    sort(v.begin(), v.end());
    li ans = 1;
    li f[200010];
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for (li i = 3; i <= 2 * n; ++i)
        f[i] = f[i - 1] * i % m;
    v.pb(mp(1000010000, 0));
    forn (i, 2 * n)
    {
        int t = 1;
        li u = 0, l = 1;
        while(i < 2 * n && v[i].first == v[i + 1].first)
        {
            if(q[v[i].second] == w[v[i].second] && !g[v[i].second])
            {
                u += 2;
                g[v[i].second] = 1;
            }
            i++;
            t++;
        }
        ans *= f[t - u];
        int r = u;
        ans %= m;
        for (int i = 1; i <= r; ++i)
        {
            li x = t + i - r;
            while(x % 2 == 0 && u > 0)
            {
                x /= 2;
                u -= 2;
            }
            ans *= x;
            ans %= m;
        }
    }
    cout << ans << endl;
    return 0;
}