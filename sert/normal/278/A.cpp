#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define fab(i, a, b) for(ll i = a; i <= b; i++)

const ll N = 1e6 + 7;

ll sum, n, s, t, a[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    fab(i, 1, n){
        cin >> a[i];
        sum += a[i];
    }

    fab(i, 2, n)
        a[i] += a[i - 1];

    cin >> s >> t;
    if (s > t)
        swap(s, t);

    ll h = a[t - 1] - a[s - 1];

    cout << min(h, sum - h);



    return 0;
}