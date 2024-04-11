#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 23;

int nreal;
int N;
ll K;

ll fac[MAXN];
ll dp[MAXN];
int arr[MAXN];

bool used[MAXN];

int par[MAXN];

int cfind (int x)
{
    if (par[x] == x) return x;
    return par[x] = cfind (par[x]);
}

bool uni (int a, int b)
{
    a = cfind (a);
    b = cfind (b);

    if (a == b) return false;
    par[a] = b;
    return true;
}

ll cc (int ind)
{
    for (int i = 0; i < N; i++)
        used[i] = false;
    for (int i = 0; i < ind; i++)
    {
        if (used[arr[i]]) return 0;
        used[arr[i]] = true;
    }

    int cloc = 0;
    while (cloc < ind && arr[cloc] < ind)
    {
        if (arr[cloc] < cloc) return 0;
        for (int i = cloc; i <= arr[cloc]; i++)
            if (arr[i] < cloc || arr[i] > arr[cloc])
                return 0;
        cloc = arr[cloc] + 1;
    }

    if (cloc == ind)
        return dp[N-ind];

    for (int i = 0; i < N; i++)
        par[i] = i;
    for (int i = cloc; i < ind; i++)
    {
        if (arr[i] < cloc || arr[i] > arr[cloc])
            return 0;
        if (!uni (i, arr[i]))
            return 0;
    }

    int nleft = arr[cloc] - ind + 1;
    return fac[max(nleft - 1, 0)] * dp[N-arr[cloc]-1];
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T = 0;
    cin >> T;

    fac[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fac[i] = fac[i-1] * i;
    dp[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= i; j++)
            dp[i] += fac[max (0, j - 2)] * dp[i-j];
    }

    for (int t = 0; t < T; t++)
    {
        cin >> N >> K;
        nreal = N;
        if (N > 22)
            N = 22;

        bool bad = false;
        for (int i = 0; i < N; i++)
        {
            int cv = 0;
            while (cv < N)
            {
                arr[i] = cv;
                ll cres = cc (i + 1);
                //cout << i << " " << cv << " " << cres << " " << K << "\n";
                if (K <= cres)
                    break;
                
                K -= cres;
                cv++;
            }
            if (cv >= N)
            {
                bad = true;
                break;
            }
        }

        if (bad)
        {
            cout << "-1\n";
        }
        else
        {
            // TODO:
            for (int i = 1; i <= nreal - N; i++)
                cout << i << " ";
            for (int i = 0; i < N; i++)
            {
                if (i) cout << " ";
                cout << arr[i] + (nreal - N + 1);
            }
            cout << "\n";
        }
    }
}