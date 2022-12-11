#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 5011;
const ll md = 1e9 + 7;

ll n, m, k;
ll p[N];
ll a[N][N];
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] += p[i - 1];
    }
    for (int len = 1; len <= n; len++)
        for (int kol = 1; kol <= k; kol++) {
            a[len][kol] = a[len - 1][kol];
            if (len >= m)
                a[len][kol] = max(a[len][kol], a[len - m][kol - 1] + p[len] - p[len - m]);
        }
    cout << a[n][k];
    //return 0;
}