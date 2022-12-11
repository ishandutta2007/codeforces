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

ll a[N];
ll n, g[N], p[N], l, m, r, ps, win, pwin, gwin;
vector <pair<int, int> > ans;
bool fail;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = n; i < n * 2 + 5; i++)
        a[i] = 1;

    for (int i = 1; i < n * 2 + 3; i++) {
        p[i] = p[i - 1];
        g[i] = g[i - 1];
        if (a[i - 1] == 1)
            p[i]++;
        else
            g[i]++;
    }

    for (int t = 1; t <= n; t++) {
        //cerr << t << ": ";
        ps = 0;
        l = 1;
        r = n * 2 + 1;
        pwin = 0;
        gwin = 0;
        fail = false;
        while (ps < n) {
            //cerr << ps << " ";
            l = ps - 1;
            r = n * 2 + 1;
            while (r - l > 1) {
                m = (l + r) / 2;
                if (p[m] - p[ps] >= t || g[m] - g[ps] >= t)
                    r = m;
                else
                    l = m;
            }
            //cerr << " (" << l << ") ";
            if (r > n) {
                fail = true;
                break;
            }
            ps = r;
            if (a[ps - 1] == 1) pwin++;
            else gwin++;
        }
        //cerr << ps << "\n";
        if (pwin == gwin || (pwin > gwin && a[n - 1] == 2) || (pwin < gwin && a[n - 1] == 1))
            fail = true;
        if (!fail)
            ans.push_back(make_pair(max(pwin, gwin), t));
    }

    sort(ans.begin(), ans.end());

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}