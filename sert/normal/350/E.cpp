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

ll a[N], b[N];
bool u[N];
int n, m, t, len, maxr;

void go(int aa, int bb) {
    cout << a[aa] + 1 << " " << a[bb] + 1 << "\n";
    m--;
    if (m == 0)
        exit(0);
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m >> t;
    int x = n - t;
    fr(i, t) {
        cin >> a[i];
        a[i]--;
        u[a[i]] = true;
    }
    len = t;
    fr(i, n)
        if (!u[i])
            a[len++] = i;

    maxr = (n * n - 3 * n + 2 * x + 2) / 2;
    if (m > maxr || t == n) {
        cout << "-1";
        return 0;
    }

    go(0, t);

    for (int i = t; i < n; i++) {
        for (int j = 1; j < t; j++)
            go(i, j);

        for (int j = i + 1; j < n; j++)
            go(i, j);
    }


    for (int i = 1; i < t; i++)
        for (int j = i + 1; j < t; j++)
            go(i, j);

    for (int i = t + 1; i < n; i++)
        go(0, i);


    return 0;
}