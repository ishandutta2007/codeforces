#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
#define ff first
#define ss second
const ll N = 1e6 + 34;


ll n, m, k, p, len, kol, ans;
string s;
int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = n - 1; i >= 0; i -= k)
        ans += a[i] * 2 - 2;
    cout << ans;
    return 0;
}