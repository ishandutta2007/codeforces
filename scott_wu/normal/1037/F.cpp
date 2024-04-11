#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;
const ll MOD = 1e9 + 7;

int N, K;
int arr[MAXN];

int nprev[MAXN], nnext[MAXN];
pair <int, int> ord[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        ord[i] = make_pair (arr[i], i);
    }
    sort (ord, ord + N);

    for (int i = 0; i < N; i++)
    {
        nprev[i] = i - 1;
        nnext[i] = i + 1;
    }

    for (int i = 0; i < N; i++)
    {
        int cloc = ord[i].second;
        if (nprev[cloc] >= 0)
            nnext[nprev[cloc]] = nnext[cloc];
        if (nnext[cloc] < N)
            nprev[nnext[cloc]] = nprev[cloc];
    }

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        ll l = i - nprev[i], r = nnext[i] - i;
        if (l > r) swap (l, r);
        ll c1 = (l + K - 3) / (K - 1);
        ll c2 = (r + K - 3) / (K - 1);
        ll c3 = (l + r + K - 3) / (K - 1);
        // 0 .. c1 x, c1 .. c2 l, c2 .. c3 (l + r - x)

        ll ntot = 0;
        ntot += c1 + ((K - 1) * (c1) * (c1 - 1)) / 2;
        ntot += (c2 - c1) * l;
        ntot += (c3 - c2) * (l + r);
        ntot += c2 + ((K - 1) * (c2) * (c2 - 1)) / 2;;
        ntot -= c3 + ((K - 1) * (c3) * (c3 - 1)) / 2;
        ntot %= MOD;
        ans = (ans + ntot * arr[i]) % MOD;
    }

    for (int i = 0; i < N; i++)
        ans = (ans - arr[i]) % MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << "\n";
}