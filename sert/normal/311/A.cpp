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
typedef long double ld;
const int N = 1e6 + 7;

ll n, s, i, x, y, k;
pair <ll, ll> a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> k;

    if (k >= (n * (n - 1)) / 2) {
        cout << "no solution\n";
        return 0;
    }

    for (int i = 0; i < n; i++) cout << "34 " << i << "\n";

    return 0;
}