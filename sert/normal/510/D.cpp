#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e5 + 7;
const int inf  = 1e9;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int n, g0, g1, cst, bst = inf;
pair <int, int> a[N];
bool u[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first;
    for (int i = 0; i < n; i++)
        cin >> a[i].second;
    srand(3431);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[j].first % a[i].first == 0 && a[i].second < a[j].second)
                u[j] = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            g1 = gcd(a[i].first, a[j].first);
            for (int k = 0; k < n; k++)
                if (a[k].first % g1 == 0 && a[k].second >= a[i].second + a[j].second)
                    u[k] = true;
        }
    for (int i = 0; i < n; i++)
        if (u[i]) {
            swap(a[i], a[--n]);
        }

    while (clock() * 10 < 19 * CLOCKS_PER_SEC) {
        random_shuffle(a, a + n);
        cst = a[0].second;
        g1 = a[0].first;
        if (a[0].first == 2316 && a[1].first == 4921) {
            cst = cst;
        }
        for (int i = 1; i < n && g1 > 1; i++) {
            g0 = g1;
            g1 = gcd(g1, a[i].first);
            if (g0 != g1)
                cst += a[i].second;
        }
        if (g1 == 1 && cst < bst)
            bst = cst;
    }

    if (bst == inf)
        cout << -1;
    else
        cout << bst;

    return 0;
}