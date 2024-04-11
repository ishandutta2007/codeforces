#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 7;

ll n, m, num, mn;
ll a[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> m >> n;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    mn = 10000000000;
    fr(i, n - m + 1) {
        if (a[i + m - 1] - a[i] < mn)
            mn = a[i + m - 1] - a[i];
    }

    cout << mn;

    return 0;
}