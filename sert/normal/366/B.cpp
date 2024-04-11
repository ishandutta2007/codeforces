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

int n, k, a[N], x, mn;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i % k] += x;
    }
    mn = 0;
    for (int i = 1; i < k; i++) if (a[mn] > a[i]) mn = i;
    cout << mn + 1 << "\n";

    return 0;
}