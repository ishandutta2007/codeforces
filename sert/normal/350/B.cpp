#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <queue>

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 5;

ll a[N], b[N], ans[N], len;
ll pr[N], n, k[N];
string s;

int go(int v, bool vyv) {
    if (vyv) {
        if (v == -1)
            return 0;
        ans[len++] = v + 1;
        if (pr[v] == -1) return 0;
        if (k[pr[v]] != 1) return 0;
        go(pr[v], vyv);
    }
    if (b[v] > 0)
        return b[v];
    if (pr[v] == -1) return b[v] = 1;
    if (k[pr[v]] != 1) return b[v] = 1;

    return b[v] = go(pr[v], vyv) + 1;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    fr(i, n) {
        cin >> b[i];
        b[i] = -b[i];
    }
    fr(i, n) {
        cin >> pr[i];
        pr[i]--;
        k[pr[i]]++;
    }

    int mx = 0;
    fr(i, n) {
        if (b[i] != -1)
            continue;
        b[i] = go(i, false);
        if (b[mx] < b[i])
            mx = i;
    }

    cout << b[mx] << "\n";
    mx = go(mx, true);

    fr(i, len)
        cout << ans[len - i - 1] << " ";


    return 0;
}