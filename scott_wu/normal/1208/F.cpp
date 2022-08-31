#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;
const int MAXD = (1 << 21) + 100;

int N;
int ncnt[MAXD];

int arr[MAXN];

void gogo (int x, int clo)
{
    if (ncnt[x] >= 2)
        return;

    ncnt[x]++;
    for (int i = clo; i <= 20; i++)
    {
        if (x & (1 << i))
        {
            gogo (x - (1 << i), i + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        // some stuff here
        int res = 0;
        for (int j = 20; j >= 0; j--)
        {
            if (arr[i] & (1 << j)) continue;
            if (ncnt[res + (1 << j)] >= 2)
                res += (1 << j);
        }
        if (i <= N - 3)
            ans = max (ans, arr[i] + res);

        gogo (arr[i], 0);
    }
    cout << ans << "\n";
}