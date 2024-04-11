#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
ll p2[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    p2[0] = 1;
    for(int i = 1; i < MAXN; i++)
        p2[i] = (p2[i - 1] + p2[i - 1]) % MOD;

    ll ans = 0;
    int cta = 0;
    string s;
    cin >> s;
    for(auto c : s) {
        if(c == 'a') cta++;
        else ans = (ans + p2[cta] - 1) % MOD;
    }
    if(ans < 0) ans += MOD;
    cout << ans << endl;
}