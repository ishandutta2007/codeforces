#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;
typedef long long ll;

int n, m;
int a[N], b[N];

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);
    if(a[n - 1] > b[0]) return cout << "-1" << endl, 0;

    ll suma = 0;
    for(int i = 0; i < n; i++) suma += a[i];

    ll res = suma * m;
//    cout << res << endl;
    ll sumb = 0;
    for(int i = 0; i < m; i++) sumb += b[i];
    res += sumb - 1LL * (m - 1) * a[n-1];
    if(b[0] == a[n-1]) res -= a[n-1];
    else res -= a[n-2];
    cout << res << endl;

}