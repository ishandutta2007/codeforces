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

int a[N], n, mn[N], ans;

int main()
{
    //freopen("a.in", "r", stdin);
    //froepen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ans = n - 1;
    for (int i = n - 2; i >= 0; i--)
        if (a[i] < a[i + 1]) ans--; else break;
    cout << ans;
    return 0;
}