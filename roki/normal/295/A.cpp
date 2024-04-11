#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<set>
#include<ctime>
#include<memory.h>
#include<vector>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int main()
{
   int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int mod = sqrt(100000.0) + 1;

    vector<li> a(n, 0);
    vector<li> p(mod, 0);

    forn (i, n)
        cin >> a[i];
    vector<li> l(m), r(m), d(m);
    forn (i, m)
    {
        scanf("%d%d%d", &l[i], &r[i], &d[i]);
        l[i]--;
        r[i]--;
    }
    vector< pair<int, int> > v;
    forn (i, k)
    {
        int p, w;
        scanf("%d%d", &p, &w);
        p--, w--;
        v.pb(mp(p, 0));
        v.pb(mp(w, 1));
    }
    
    sort(v.begin(), v.end());

    int q = 0;
    li cnt = 0;

    for (int i = 0; i < m; ++i)
    {
        while(q < v.size() && v[q].first < i || (v[q].first == i && v[q].second != 1))
        {
            if(v[q].second == 0)
                cnt++;
            else
                cnt--;
            q++;
        }
        while(l[i] <= r[i])
        {
            if(l[i] % mod == 0 && l[i] + mod <= r[i])
            {
                p[l[i] / mod] += cnt * d[i];
                l[i] += mod;
            }
            else
                a[l[i]++] += cnt * d[i];
        }
    }
    forn (i, n)
       printf("%I64d ", a[i] + p[i / mod]);
    return 0;
}