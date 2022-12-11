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

int n, m, a, b, c, t[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        if (t[a] != 0) {t[b] = t[a] % 3 + 1; t[c] = t[b] % 3 + 1;}
        else if (t[b] != 0) {t[c] = t[b] % 3 + 1; t[a] = t[c] % 3 + 1;}
        else if (t[c] != 0) {t[b] = t[c] % 3 + 1; t[a] = t[b] % 3 + 1;}
        else {t[a] = 1; t[b] = 2; t[c] = 3;}
    }

    for (int i = 1; i <= n; i++) printf("%d ", t[i]);

    return 0;
}