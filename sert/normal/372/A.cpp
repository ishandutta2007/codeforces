#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

#define y1 yy1
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;

using namespace std;

const ll N = 1e6 + 34;

ll n, l, r, m, a[N];
bool fail;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    l = 0;
    r = n / 2 + 1;

    while (r - l > 1) {
        m = (l + r) / 2;
        fail = false;
        for (int i = 0; i < m && !fail; i++)
            if (a[i] * 2 > a[n - m + i]) fail = true;
        if (fail) r = m; else l = m;
    }
    cout << n - l;


    return 0;
}