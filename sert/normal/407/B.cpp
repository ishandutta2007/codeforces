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
#include <cstdlib>
#include <cstring>

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 5;

ll n, t[N], tv[N], ans, av, p[N];
const ll md = 1e9 + 7;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    t[0] = 0;

    for (int i = 1; i <= n; i++) {
        ans = (t[i - 1] + 1) % md;
        av = ((i - 1) - p[i - 1] + 1 + md) % md;
        for (int j = p[i - 1]; j < i - 1; j++)
            av = (av + tv[j]) % md;
        tv[i - 1] = av;
        t[i] = (ans + av) % md;
    }

    cout << t[n];

    return 0;
}