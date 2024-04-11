#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef int ll;
const int N = 3e6 + 7;
const int inf = 1e9 + 34;

ll n, m, z;
ll t[N], ans[N], ind[N];
pair <pair<int, int>, int> a[N];
pair <pair<int, int>, pair<int, int> > b[N];
set <pair<int, int> > s;
set <pair<int, int> > :: iterator it;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &n);
    //cerr << n << m << "\n";
    for (int i = 0; i < n; a[i].ss = i++) {
        scanf("%d%d", &a[i].ff.first, &a[i].ff.second);
    }
    sort(a, a + n);
    scanf("%d", &m);
    //cerr << n << m << "\n";
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &b[i].ff.first, &b[i].ff.second, &b[i].ss.ff);
        b[i].ss.ss = i;
    }
    sort(b, b + m);
    b[m] = make_pair(make_pair(inf, inf), make_pair(inf, inf));

    //cerr << "ok\n";

    int uk = 0;
    for (int i = 0; i < n; i++) {
        while (b[uk].ff.ff <= a[i].ff.ff) {
            s.insert(make_pair(b[uk].ff.ss, uk));
            uk++;
        }
        it = s.lower_bound(make_pair(a[i].ff.ss, -34));
        if (it == s.end()) {
            printf("NO\n");
            return 0;
        }
       // if (it == s.begin()) cerr << "iz\n";

        z = (*it).second;

        ans[a[i].ss] = b[z].ss.ss;

        ind[z]++;
        if (ind[z] == b[z].ss.ff)
            s.erase(it);

        /*for (auto q = s.begin(); q != s.end(); q++)
            cerr << "(" << q->first << " " << q->second << "), ";
        cerr << "\n";*/
        //cerr << s.size() << "\n";

    }

    printf("YES\n");
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i] + 1);

    return 0;
}