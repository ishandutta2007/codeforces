#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 3000;
const ll md = 1e9 + 7;

ll n, x, ans = 1, sum;
ll c[N][N];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    c[0][0] = 1;
    for (int i = 1; i < N; i++) {
        c[i][i] = c[i][0] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % md;
    }
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        // sum + 1
        // x - 1
        // sum + x - 1 <-> sum
        ans = (ans * c[sum + x - 1][sum]) % md;
        sum += x;
    }

    cout << ans;

    //return 0;
}