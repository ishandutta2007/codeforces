#include <iostream>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

const int N = 1e6 + 34;

#define ff first
#define ss second

set <pair<int, int> > s;
int p, v, n, kl, t;
int kol[N];
vector <int> es[N];
pair<int, int> c[N], hl;
long long ans;
long long pr[N];

int main()
{
    //freopen("a.in", "r", stdin);

    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> c[i].ff >> c[i].ss;
        c[i].ff--;
        c[i].ss--;
        es[c[i].ff].push_back(i);
        es[c[i].ss].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        kol[i] = es[i].size();
        pr[kol[i]]++;
    }

    for (int i = n - 2; i >= 0; i--)
        pr[i] += pr[i + 1];

    for (int i = 0; i < n; i++) {

        kl = p - kol[i];

        ans += pr[max(kl, 0)];

        if (kol[i] >= kl)
            ans --;

        for (int j = 0; j < es[i].size(); j++) {
            t = es[i][j];
            v = c[t].ff + c[t].ss - i;
            kol[v]--;
            if (kol[v] == kl - 1)
                ans--;
        }


        for (int j = 0; j < es[i].size(); j++) {
            t = es[i][j];
            v = c[t].ff + c[t].ss - i;
            kol[v]++;
        }
    }

    cout << ans / 2;

    return 0;
}