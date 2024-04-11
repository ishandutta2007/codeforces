#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <cstring>

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef int ll;
typedef long double ld;
const ll N = 2e5 + 5;
const ll M = 3000;
const int inf = 1e9 + 7;

int t, ans;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
int n, m;
cin >> n >> m;
for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
    cin >> t;
    if (t == 1) if (i == 0 || i == n - 1 || j == 0 || j == m - 1) ans = 1;
} if (ans) cout << 2; else cout << 4;

    return 0;
}