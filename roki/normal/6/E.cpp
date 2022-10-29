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

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    forn (i, n)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    int maxv = 0, l = 1;
    a.pb(1e9);
    set<pair<int, int>> S;
    forn (i, n)
    {
        if(S.size() == 0)
            S.insert(mp(a[i], i));
        set<pair<int, int>>::iterator it = S.end();
        it--;
        while(a[l] - S.begin()->first <= k && it->first - a[l] <= k)
        {
            S.insert(mp(a[l], l));
            l++;
            it = S.end();
            it--;
        }
        maxv = max(maxv, l - i);
        S.erase(mp(a[i], i));
    }
    vector<pair<int, int>> ans;
    set<pair<int, int>> s;
    forn (i, maxv)
        s.insert(mp(b[i], i));
    forn (i, n - maxv + 1)
    {
        if(i != 0)
            s.insert(mp(b[i + maxv - 1], i + maxv - 1));
        set<pair<int, int>>::iterator it1 = s.begin();
        set<pair<int, int>>::iterator it2 = s.end();
        it2--;
        if(it2->first - it1->first <= k)
            ans.pb(mp(i, i + maxv));
        s.erase(mp(b[i], i));
    }
    cout << maxv << ' ' << ans.size() << endl;
    forn (i, ans.size())
        cout << ans[i].first + 1 << ' ' << ans[i].second << endl;
}