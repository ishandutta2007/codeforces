#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
int a[MAXN];
ll prf[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        prf[i] = prf[i - 1] + a[i];
    }
    ll ans = 0;
    map<ll, int> ac;
    ac[prf[0]]++;
    for(int l = 0, r = 1; l < n; l++) {
        while(r <= n && ac[prf[r]] == 0)
            ac[prf[r++]]++;
        ans += r - l - 1;
        ac[prf[l]]--;
    }
    cout << ans << '\n';
}