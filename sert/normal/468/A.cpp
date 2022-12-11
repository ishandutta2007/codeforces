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

    cin >> n;

    if (n < 4) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    if (n == 4) {
        cout << "1 + 2 = 3\n";
        cout << "3 + 3 = 6\n";
        cout << "6 * 4 = 24\n";
        return 0;
    }

    if (n == 5) {
        cout << "4 * 5 = 20\n";
        cout << "20 + 3 = 23\n";
        cout << "23 + 2 = 25\n";
        cout << "25 - 1 = 24\n";
        return 0;
    }

    cout << "1 + 2 = 3\n";
    cout << "3 - 3 = 0\n";
    cout << "5 * 0 = 0\n";

    for (int i = 7; i <= n; i++)
        cout << i << " * 0 = 0\n";

    cout << "4 * 6 = 24\n";
    cout << "0 + 24 = 24\n";

    return 0;
}