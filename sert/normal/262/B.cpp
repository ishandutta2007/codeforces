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

string s;
ll n, k, mm = N, o;
ll a[N], b[N], c[N], sum;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mm = min(abs(a[i]), mm);
        if (a[i] <= 0) o++;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (i < k && a[i] < 0) sum -= a[i]; else sum += a[i];
    }
    if ((o + k) % 2 && o < k) sum -= 2 * mm;
    cout << sum;
    return 0;
}