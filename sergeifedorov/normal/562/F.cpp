#ifdef blabla
//#define _GLIBCXX_DEBUG
#endif

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i ++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define all(a) a.begin(), a.end()
#define sqr(a) ((a)*(a))

const int nmax = 1000*1000;

typedef pair<int, int> pii;

struct ms {
    string s;
    int id1, id2;
};

char buf[nmax];
ms a[nmax];
int n;

int ans;
vector<pii> res;
set<pair<int, pii> > h;
set<int> u;


bool ls(const ms &a, const ms &b) {
    return a.s < b.s;
}

int lcp(const string&a, const string &b) {
    int len = min(a.size(), b.size());
    forn(i, len)
        if (a[i] != b[i])
            return i;
    return len; 
}

int main() {
#ifdef blabla
    freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#endif
    scanf("%d\n", &n);
    forn(i, n) {
        scanf(" %s ", buf);
        a[i].s = buf;
        a[i].id2 = 1;
        a[i].id1 = i + 1;
    }
    forn(i, n) {
        scanf(" %s ", buf);
        a[n+i].s = buf;
        a[n+i].id2 = 2;
        a[n+i].id1 = i + 1;
    }
    sort(a, a + 2 * n, ls);
    forn(i, 2 * n) {
        u.insert(i);        
    }

    forn(i, 2 * n - 1) {
        if (a[i].id2 != a[i+1].id2) {
            int now = lcp(a[i].s, a[i+1].s);
            h.insert(mp(now, mp(i, i + 1)));
        }
    }

    while(u. size() > 0) {
        pair<int, pii> now = *(--h.end());
        h.erase(now);
        pii w = now.sc;
        if (a[w.fs].id2 == 2)
            swap(w.fs, w.sc);
        if (u.count(w.fs) == 0 || u.count(w.sc) == 0)
            continue;
            
        ans += now.fs;
        pii q = mp(a[w.fs].id1, a[w.sc].id1);
        res.pb(q);

        u.erase(w.fs);
        u.erase(w.sc);

        if (u.size() > 0) {
            set<int> :: iterator it1, it2;
            it1 = u.lower_bound(min(w.fs, w.sc));
            it2 = u.lower_bound(max(w.fs, w.sc));
            if (it1 == u.begin() || it2 == u.end())
                continue;

            int left = *(--it1);
            int right = *(it2);
            if (a[left].id2 != a[right].id2) {
                int now = lcp(a[left].s, a[right].s);
                h.insert(mp(now, mp(left, right)));
            }
        }
    }

    cout << ans << endl;
    forn(i, res.size())
        printf("%d %d\n", res[i].fs, res[i].sc);
    

    return 0;
}