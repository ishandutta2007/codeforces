#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 500100;

ll gcf (ll a, ll b)
{
    if (b == 0) return a;
    return gcf (b, a % b);
}

int N;
ll a[MAXN], b[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i] >> b[i];

    ll g = a[0] * b[0];
    for (int i = 1; i < N; i++)
    {
        g = gcf (g, a[i] * b[i]);
    }

    ll l = gcf (a[0], g), r = gcf (b[0], g);
    if (l == 1 && r == 1)
    {
        cout << "-1\n";
        return 0;
    }

    if (l < r)
        swap (l, r);

    for (ll i = 2; i * i <= l; i++)
    {
        if (l % i == 0)
        {
            cout << i << "\n";
            return 0;
        }
    }
    cout << l << "\n";
    return 0;
}