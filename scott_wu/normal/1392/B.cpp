#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
ll K;
ll arr[MAXN];

void gogo()
{
    ll lo = 1e10, hi = -1e10;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        lo = min (lo, arr[i]);
        hi = max (hi, arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        if (K % 2 == 0) cout << arr[i] - lo;
        else cout << hi - arr[i];
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        gogo();
    }
}