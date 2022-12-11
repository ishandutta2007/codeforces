#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ll n;
ll a[N];
bool u[N];
vector <ll> p;
ll ans;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    for (int i = n - 1; i > 0; i--) {
        if (u[i]) continue;
        if (a[i] - 1 <= a[i - 1]) {
            u[i - 1] = true;
            p.push_back(a[i - 1]);
        }
    }

    for (int i = 1; i < p.size(); i += 2)
        ans += p[i] * p[i - 1];

    cout << ans;

    //return 0;
}