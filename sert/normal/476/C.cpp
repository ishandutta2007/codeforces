#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ll a, b;
ll ans, t1, t2;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> a >> b;

    ans = (((b - 1) * b) / 2) % md;
    ans = (ans * a) % md;
    t1 = ((a * (a + 1)) / 2) % md;
    t2 = (((b - 1) * b) / 2) % md;
    t2 = (t2 * b) % md;

    cout << (ans + t1 * t2) % md;

    //return 0;
}