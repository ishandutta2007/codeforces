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

const ll N = 2014;

int a[N][N], n, k, md = 1e9 + 7, ans;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) a[1][i] = 1;

    for (int i = 1; i < k; i++)
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0) continue;
            for (int ii = 1; ii * j <= n; ii++)
                a[i+1][ii * j] = (a[i+1][ii * j] + a[i][j]) % md;
        }
    for (int i = 1; i <= n; i++)
        ans = (ans + a[k][i]) % md;

    cout << ans;

    return 0;
}