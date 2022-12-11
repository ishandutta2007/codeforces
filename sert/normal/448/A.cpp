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

ll a1, a2, a3, b1, b2, b3, n;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
    if ((a1 + a2 + a3 + 4) / 5 + (b1 + b2 + b3 + 9) / 10 > n) cout << "NO\n"; else cout << "YES\n";
    return 0;
}