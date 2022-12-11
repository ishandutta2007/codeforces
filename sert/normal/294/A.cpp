#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

#define fr(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 7;
const ll M = 1e3 + 7;

using namespace std;

ll n, a[N], m, k, h, y, x;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;

    fr(i, n) cin >> a[i];

    cin >> m;
    fr(i, m){
        cin >> y >> x;
        if (y != 1)
            a[y - 2] += x - 1;
        if (y != n)
            a[y] += a[y - 1] - x;
        a[y - 1] = 0;
    }

    fr(i, n)
        cout << a[i] << "\n";

    return 0;
}