#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5;
ll arr[MAXN];


int main() {
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    ll cur = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(cur - arr[i]);
        cur = arr[i];
    }

    cout << ans << '\n';

    return 0;
}