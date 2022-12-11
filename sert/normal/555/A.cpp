#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N];
ll n, m, ans, k;
bool ok;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> k;

    ans = n * 2 - k - 1;

    for (int i = 0; i < k; i++) {
        cin >> m;
        for (int j = 0; j < m; j++)
            cin >> a[j];
        for (int j = 1; j < m; j++)
            if (a[j] == j + 1)
                ans -= 2;
    }

    cout << ans;

    return 0;
}