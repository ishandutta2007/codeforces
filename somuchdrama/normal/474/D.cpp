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

const int MAXN = 1e5;
const ll MOD = 1e9+7;
ll arr[MAXN+1], sum[MAXN+1];

int main() {
    ios_base::sync_with_stdio(0);
    srand(time(0));
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int t, k;
    cin >> t >> k;    
    for (int i = 0; i < k; ++i) 
        arr[i] = 1;
    for (int i = k; i <= MAXN; ++i)
        arr[i] = (arr[i-1] + arr[i-k]) % MOD;
    sum[0] = 0;
    for (int i = 1; i <= MAXN; ++i)
        sum[i] = (sum[i-1] + arr[i]) % MOD;

    for (int i = 0; i < t; ++i) {
        int l, r;
        cin >> l >> r;
        cout << (sum[r] - sum[l - 1] + MOD) % MOD << '\n';
    }

    return 0;
}