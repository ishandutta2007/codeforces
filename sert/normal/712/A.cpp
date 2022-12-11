#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int)1e6 + 34;
const ll INF = 1e18;

ll n, a[N], h;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cout << a[i] + a[i + 1] << " ";
    return 0;
}