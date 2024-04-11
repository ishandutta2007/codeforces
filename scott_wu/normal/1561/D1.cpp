#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 4000100;

int N, M;
ll res[MAXN];
ll dres[MAXN];

void gogo()
{
    for (int i = 0; i < MAXN; i++)
    {
        res[i] = 0;
        dres[i] = 0;
    }

    cin >> N >> M;

    dres[1] = 1;
    for (int i = 1; i <= N; i++)
    {
        res[i] = (2 * res[i-1] + dres[i]) % M;
        if (i == 2) res[i]--;


        for (int j = 2 * i; j <= N; j += i)
            dres[j] = (dres[j] + (res[i] - res[i-1] + M)) % M;
    }

    cout << res[N] % M << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T = 1;
    for (int t = 0; t < T; t++)
        gogo();
}