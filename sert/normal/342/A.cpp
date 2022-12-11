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

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 5;

ll a[N];
ll n, k;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    fr(i, n) {
        cin >> k;
        a[k]++;
    }
    if (3 * (a[2] + a[3]) == n && 3 * (a[4] + a[6]) == n && 3 * a[1] == n && a[3] + a[4] <= n / 3) {
        fr(i, a[4]) cout << "1 2 4\n";
        fr(i, a[3]) cout << "1 3 6\n";
        fr(i, n / 3 - a[3] - a[4]) cout << "1 2 6\n";
    }
    else cout << "-1";
    return 0;
}