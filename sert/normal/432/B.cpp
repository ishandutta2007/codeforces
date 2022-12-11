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
int a1[N], a2[N];
bool d[N], g[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
int n, m;
cin >> n;
for (int i = 0; i < n; i++) {
    cin >> t >> a1[i];
    a2[t]++;
}
int q;
for (int i = 0; i < n; i++) {
    q = a2[a1[i]];
    printf("%d %d\n", n - 1 + q, n - 1 - q);
}
    return 0;
}