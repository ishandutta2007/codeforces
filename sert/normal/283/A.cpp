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

ll sum, kol = 1;
ll pr[N], n, t, x, a, b[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    cout.precision(10);
    while (n--) {
        cin >> t;
        if (t == 1) {
            cin >> x >> a;
            pr[x] += a;
            sum += a * x;
        }
        if (t == 2) {
            cin >> x;
            b[kol] = x;
            sum += x;
            kol++;
        }
        if (t == 3) {
            sum -= pr[kol];
            sum -= b[kol - 1];
            pr[kol - 1] += pr[kol];
            pr[kol] = 0;
            kol--;
        }
        printf("%.9lf\n", (sum + 0.0) / (kol + 0.0));
    }
    return 0;
}