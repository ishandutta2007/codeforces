#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 2014;

ll a[N], n, h, b[N];
ll t;

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h;
        for (int i = 1; i <= h; i++)
            a[i]++;
    }
    for (int i = 1; i <= 102; i++)
    for (int j = n; j >= n - a[i] + 1; j--)
        b[j]++;

    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";



    return 0;
}