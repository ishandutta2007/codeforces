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

int n, a[N], m1, m2;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    m1 = a[1] - a[0];
    m2 = a[2] - a[0];

    for (int i = 2; i < n; i++) m1 = max(m1, a[i] - a[i - 1]);
    for (int i = 3; i < n; i++) m2 = min(m2, a[i] - a[i - 2]);

    cout << max(m1, m2);

    return 0;
}