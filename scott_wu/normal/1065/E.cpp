#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXM = 200100;
const ll MOD = 998244353;

ll N, A;
int M;
ll B[MAXM];

ll gpow (ll exp)
{
    if (exp == 0) return 1;
    if (exp == 1) return A;
    ll r = gpow (exp / 2);
    r = (r * r) % MOD;
    if (exp & 1)
        r = (r * A) % MOD;
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M >> A;
    ll llast = 0;
    ll ans = 1;
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
        ll rv = (gpow (2 * (B[i] - llast)) + gpow (B[i] - llast)) + MOD;
        ans = (ans * rv) % MOD;
        ans = (ans * (MOD + 1) / 2) % MOD;
        llast = B[i];
    }

    ans = (ans * gpow (N - 2 * llast)) % MOD;
    cout << ans << "\n";
}