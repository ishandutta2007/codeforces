#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 500100;

int N, M;
ll X;
ll arr[MAXN];

int pp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    M = N / 2 + 1;
    for (int i = N / 2; i >= (1 - N % 2); i--)
        cin >> arr[i];
    cin >> X;

    ll csum = 0;
    for (int i = 0; i < M; i++)
    {
        csum += arr[i];

        int maxb = i + M;
        if (X > 0)
        {
            if (csum <= 0)
            {
                ll lo = i + 1 + (-csum) / X + 1;
                pp[0]++;
                pp[min (lo, (ll) maxb+1)]--;
            }
        }
        else if (!X)
        {
            if (csum <= 0)
            {
                pp[0]++;
                pp[maxb+1]--;
            }
        }
        else
        {
            if (csum <= 0)
            {
                pp[0]++;
                pp[maxb+1]--;
            }
            else
            {
                ll lo = (csum - 1) / -X;
                pp[min(lo + i + 1, (ll) maxb) + 1]++;
                pp[maxb+1]--;
                //cout << i << " " << lo << " " << maxb << "\n";
            }
        }
    }

    int ans = -1;
    int cs = 0;
    for (int i = 0; i <= 2 * M - 1; i++)
    {
        cs += pp[i];
        if (!cs && i >= M)
            ans = i;
    }
    if (ans == -1)
        cout << "-1\n";
    else
    {
        if (N % 2 == 0) ans--;
        cout << ans << "\n";
    }
}