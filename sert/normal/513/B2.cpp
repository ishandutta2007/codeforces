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

ll n, m, q;
ll a[N];
ll us, uf;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;

    if (n == 1) {cout << 1; return 0;}

    m--;

    us = 0;
    uf = n - 1;
    q = (1ll << (n - 2));

    for (int i = n; i > 0; i--) {
        if (m < q)
            a[us++] = n - i + 1;
        else {
            a[uf--] = n - i + 1;
            m -= q;
        }
        q /= 2;
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";


    return 0;
}