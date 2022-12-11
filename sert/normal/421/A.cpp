#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 5003;
int n, k, m, x, a[N];
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> k >> n >> m;
    for (int i = 0; i < n; i++) {cin >> x; a[x - 1] = 1;}
    for (int i = 0; i < m; i++) {cin >> x; a[x - 1] = 2;}
    for (int i = 0; i < k; i++) cout << a[i] << " ";


    return 0;
}