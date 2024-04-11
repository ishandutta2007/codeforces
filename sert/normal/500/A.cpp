#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll n, t, cur, a[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> t;
    t--;
    for (int i = 0; i < n - 1; i++)
        cin >> a[i];
    while (cur < t) {
        cur += a[cur];
    }
    if (cur == t) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}