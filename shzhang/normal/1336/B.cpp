#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define ll long long

pair<ll, int> seq[300005];
int nxt[300005][4];

int nr, ng, nb, n;

#define sq(a) ((a)*(a))

ll absolute(ll a)
{
    return a >= 0LL ? a : -a;
}

#define value(x) (sq(left-x)+sq(right-x))

ll search(vector<ll>& a, ll left, ll right)
{
    int l = 0; int r = a.size() - 1;
    while (l < r) {
        int mid1 = (l + r) / 2;
        int mid2 = (l + r) / 2 + 1;
        if (value(a[mid1]) < value(a[mid2])) {
            r = mid1;
        } else {
            l = mid2;
        }
    }
    return a[l];
}

void work(void)
{
    scanf("%d%d%d", &nr, &ng, &nb);
    vector<ll> vals[4];
    n = nr + ng + nb;
    for (int i = 1; i <= nr; i++) {
        pair<ll, int> pr; pr.second = 1;
        scanf("%lld", &(pr.first)); seq[i] = pr;
        vals[1].push_back(pr.first);
    }
    for (int i = nr + 1; i <= nr + ng; i++) {
        pair<ll, int> pr; pr.second = 2;
        scanf("%lld", &(pr.first)); seq[i] = pr;
        vals[2].push_back(pr.first);
    }
    for (int i = nr + ng + 1; i <= n; i++) {
        pair<ll, int> pr; pr.second = 3;
        scanf("%lld", &(pr.first)); seq[i] = pr;
        vals[3].push_back(pr.first);
    }
    sort(seq + 1, seq + n + 1);
    for (int i = 1; i <= 3; i++) sort(vals[i].begin(), vals[i].end());
    for (int i = 1; i <= 3; i++) {
        vector<ll> new_v;
        for (int j = 0; j < vals[i].size(); j++) {
            if (j == 0 || vals[i][j] != vals[i][j-1]) {
                new_v.push_back(vals[i][j]);
            }
        }
        swap(new_v, vals[i]);
    }
    for (int i = 1; i <= 3; i++) nxt[n][i] = 0;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= 3; j++) {
            if (seq[i+1].second == j) {
                nxt[i][j] = i + 1;
            } else {
                nxt[i][j] = nxt[i+1][j];
            }
        }
    }
    ll ans = 5000000000000000000LL;
    for (int i = 1; i <= n; i++) {
        int clr1 = seq[i].second;
        for (int clr2 = 1; clr2 <= 3; clr2++) {
            if (clr1 == clr2) continue;
            for (int clr3 = 1; clr3 <= 3; clr3++) {
                if (clr1 == clr3 || clr2 == clr3) continue;
                int j = nxt[nxt[i][clr2]][clr3];
                if (!j) continue;
                ll val = search(vals[clr2], seq[i].first, seq[j].first);
                //printf("found %lld\n", val);
                ans = min(ans, sq(seq[i].first - val) + sq(seq[j].first - val) +
                    sq(seq[i].first - seq[j].first));
            }
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}