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

ll n, m, a[N], l, lst = -34, h;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    while (m--) {
        cin >> l >> h;
        lst = h + max(lst, a[l - 1]);
        printf("%I64d\n", lst - h);
    }

    return 0;
}