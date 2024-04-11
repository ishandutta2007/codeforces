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

ll a[N], b[N];
ll n, k, p, t, h, m;
string s;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    fr(i, n)
        cin >> a[i];
    fr(i, m)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    t = max(a[0] * 2, a[n - 1]);

    if (t >= b[0])
        cout << -1;
    else
    {
        cout << t;

    }

    return 0;
}