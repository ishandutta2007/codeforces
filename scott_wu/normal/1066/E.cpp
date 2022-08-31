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
const int MAXN = 200100;
const ll MOD = 998244353;

int N, M;
int a[MAXN], b[MAXN];
int pow2[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        char c; cin >> c;
        if (c == '1') a[N-1-i] = 1;
    }
    for (int i = 0; i < M; i++)
    {
        char c; cin >> c;
        if (c == '1') b[M-1-i] = 1;
    }

    pow2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pow2[i] = (2 * pow2[i-1]) % MOD;

    int nc = 0, ans = 0;
    for (int i = MAXN - 1; i >= 0; i--)
    {
        nc += b[i];
        if (a[i])
            ans = (ans + nc * (ll) pow2[i]) % MOD;
    }
    cout << ans << "\n";
}