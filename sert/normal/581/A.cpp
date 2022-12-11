#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N];
ll n, m, t, k;
string s;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> m;
    cout << min(n, m) << " " << (max(n, m) - min(n, m)) / 2;

    return 0;
}