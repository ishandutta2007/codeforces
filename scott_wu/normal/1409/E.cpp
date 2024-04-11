#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N, K;
int x[MAXN], y[MAXN];
int nb[MAXN], nn[MAXN];

void gogo()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> x[i];
    for (int i = 0; i < N; i++)
        cin >> y[i];

    sort (x, x + N);

    for (int i = 0; i < N; i++)
    {
        nb[i] = lower_bound (x, x + N, x[i] + K + 1) - x;
        //cout << i << " " << nb[i] << "\n";
    }
    nn[N] = 0;
    int ans = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        nn[i] = max (nn[i+1], nb[i] - i);
        ans = max (ans, nb[i] - i + nn[nb[i]]);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}