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

typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 5;

struct pt {
    ll x, y;
    ll len() {
        return x * x + y * y;
    }
    ll operator % (const pt &a) {
        return x * a.x + y * a.y;
    }
};

ll r1, r2;
ll ax[N], bx[N], ay[N], by[N];
ll la, lb;
string s;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> r1 >> r2;

    for (int x = -1100; x <= 1100; x++)
    for (int y = -1100; y <= 1100; y++) {
        if (x == 0 || y == 0)
            continue;
        if (x * x + y * y == r1 * r1) {
            ax[la] = x;
            ay[la] = y;
            la++;
        }
        if (x * x + y * y == r2 * r2) {
            bx[lb] = x;
            by[lb] = y;
            lb++;
        }
    }

    for (int i = 0; i < la; i++)
    for (int j = 0; j < lb; j++) {
        if (ax[i] != bx[j] || ay[i] != by[j])
        if (ax[i] * bx[j] + ay[i] * by[j] == 0 && ax[i] != bx[j] && ay[i] != by[j]) {
            cout << "YES\n0 0\n";
            cout << ax[i] << " " << ay[i] << "\n";
            cout << bx[j] << " " << by[j] << "\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}