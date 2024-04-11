#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

typedef int ll;

const int N = 1e6 + 7;

ll n;
pair <ll, ll> a[N];

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    return x.second < y.second;
}

int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        if (i > 0)
            a[i].first = max(a[i].first, 1 + a[i - 1].first);
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
        cout << a[i].first << " ";

    return 0;
}