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

struct otr
{
    int a, b, c;
};

bool cmp(otr &a, otr &b)
{
    if(a.a != b.a)
        return a.a < b.a;
    if(a.b != b.b)
        return a.b > b.b;
    return a.c < b.c;
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &m, &n);

    vector< otr > v(n);

    forn(i, n)
    {
        scanf("%d%d", &v[i].a, &v[i].b);
        v[i].b += v[i].a - 1;
        v[i].c = i;
    }

    sort(v.begin(), v.end(), cmp);

    vector<int> ans;

    int maxr = -1, l = 0, r = 0;
    int pos = 0, last = 0;

    while(l < n)
    {
        if(v[l].a > maxr)
        {
            last = l;
            maxr = v[l].b;
        }
        int nmaxr = maxr;   
        while(r < n && v[r].a <= maxr + 1)
        {
            if(v[r].b > nmaxr)
            {
                nmaxr = v[r].b;
                pos = r;
            }
            r++;
        }
        while(l < r)
        {
            if(pos != l && last != l)
                ans.pb(v[l].c);
            l++;
        }
        maxr = nmaxr;
    }
    cout << ans.size() << endl;
    forn (i, ans.size())
        cout << ans[i] + 1 << ' ';
    return 0;
}