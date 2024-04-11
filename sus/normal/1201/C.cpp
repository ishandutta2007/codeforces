#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'

int N, K, A[200005];

ll numOps(ll m) {
    ll ans = 0;
    for (int i = N / 2; i < N; i++)
        ans += max(0LL, m - A[i]);
    return ans;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);
    ll l = 1, r = 2000000000;
    while (l < r) {
        ll m = (l + r + 1) / 2;
        if (numOps(m) <= K)
            l = m;
        else 
            r = m - 1;
    }
    cout << l << '\n';
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}